/*
________       ___  ___      ________      ________       ________
|\   __  \     |\  \|\  \    |\   __  \    |\   ____\     |\   __  \
\ \  \|\  \    \ \  \\\  \   \ \  \|\  \   \ \  \___|_    \ \  \|\  \
 \ \  \\\  \    \ \  \\\  \   \ \   __  \   \ \_____  \    \ \   _  _\
  \ \  \\\  \    \ \  \\\  \   \ \  \ \  \   \|____|\  \    \ \  \\  \|
   \ \_____  \    \ \_______\   \ \__\ \__\    ____\_\  \    \ \__\\ _\
    \|___| \__\    \|_______|    \|__|\|__|   |\_________\    \|__|\|__|
          \|__|                               \|_________|



                               ````````````
                           ```````````...::/::..`
                            ``             ``...:/:..`
                       `       `.`.`.-..-.````    ```.-.`
                        `.---......`..``..``..--..`   `.::.`
                    ``..```````````......````````.--.....`..`
                `-:-..`    `.:/++/++oooossso+:.`````--:-.``..`     `
              `.-:```  ``-///::--::/ossshyyhhhs+/..```.-..` `.`    .`
          ```..-.`  ``:+o:-..-/ooo////////:/+yysyo-.`  `..-.` `    `
         `.``..`   `-+o:-.`:o+++::::::++oo/-/ssos+-:-.  `//. `..   -.
        `` `+.`   `-+y:-``:++-::--:+/:///omd+:/--.-oo-` `:+.  -.   --`
          `.-    .::+o...:+s/-+..+:.`-/sydy:-+.`/.+oh/```os. `/.  `/.
         `-:`   `///o+.`./++///`:o. /mNNmo` -o.-/.-so:``:o:````  `:-`
         ./:    .---::. `:ys/::-./ssmh+:..:/o::/::o+-../s--..`  .-`
         `-.`  `...`./o-`.-/+yso/--+ysssooo+::+/+oo-.-ss/.-` `.-:`
          .-`   ..` `./+.``.-+shso+::::::///+ossss+://+-````:+/.
           `.    `.`  ./+/....-/ooyyyysossssysss+:--.```.////-`
            ``    `-/  `-o:....`..-:://///:/:-..`````.:oso:.
                    ..`  ./o/-.``...---..----:-::++/+::.`
                    `-:.```.://+:--.----::/+oo/:--.````
             `.`      `.---.`````.-::::--..`` `````        ..`
               `         `..--.``     ```````     ``````.```
                            ``--.....``..```...--.``
                                    `......`````


Filename : qr_mongo_cm.js
By: fsabatie <fsabatie@student.42.fr>
Created: 2018/12/19 20:38:58 by fsabatie
Updated: 2019/03/12 23:24:44 by fsabatie
*/
const Rfr			= require('rfr');
const MongoDB		= require('mongodb');
const Util			= require('util');

// TODO : Encapsulate all the methods inside the constructor d

class Mongo {
	/** Mongo constructor class : gets the mongo client on initialization */
	constructor(dbUrl, cb) {
		this.client = false;
		this.mdb = false;
		this.Promises = {
			addElements: Util.promisify(this.addElements),
			setElements: Util.promisify(this.setElements),
			pullElement: Util.promisify(this.pullElement),
			findDocument: Util.promisify(this.findDocument),
			deleteDocument: Util.promisify(this.deleteDocument),
			pushDataToElement: Util.promisify(this.pushDataToElement)
		}
		MongoDB.MongoClient.connect(dbUrl, { useNewUrlParser: true }, (err, client) => {
			if (err) { return (cb(`Could not fetch the mongo client : ${err}`)) }
			this.client = client;
			this.mdb = client.db(__MONGO_DBNAME);
			console.log('Connected to the client');
			return (cb(null, this));
		});
	}

	/**
	Finds a document in the collection given, and returns it. The data must be a valid JSON string,
	and using the _id to find the document implies that _id is a mongodb ObjectID object.
	**/
	findDocument(collection, data, cb) {
		this.mdb.collection(collection).findOne(data, (err, foundDoc) => {
			if (err) { return (cb(err)) }
			if (foundDoc == null || foundDoc == []) return (cb("Could not find the document"));
			return (cb(null, foundDoc));
		})
	}

	/**
	Pushes the data to an element in the collection given, and returns the pushed element.
	**/
	pushDataToElement(collection, element, data, cb) {
		this.mdb.collection(collection).findOneAndUpdate(element, {$push : data}, {returnOriginal : false}, (err, inserted) => {
			if (err) return (cb(err));
			return (cb(null, inserted));
		});
	};

	/**
	Removes the document found using the query. Query must be a valid JSON string. If using the _id
	to find the document implies that _id is a mongodb ObjectID object.
	**/
	deleteDocument(collection, query, cb) {
		this.mdb.collection(collection).deleteMany(query, (err, removedDoc) => {
			if (err) return (cb(err));
			return (cb(null, removedDoc));
		})
	}

	/**
	Removes one or all elements in a doc array matching the data specs.
	Eg : pullElement('users', {_id : 1234}, {pets : {'type' : 'dog'}}, true)
	-> Removes all dogs of the user 1234 (if set to false, only the first dog is removed)
	**/
	pullElement(collection, docSpecs, data, multi = true, cb) {
		let query = {$pull : data};
		ret.result.mdb.collection(collection).updateOne(docSpecs, query, {multi : multi}, (err, updated) => {
			if (err) return (err);
			return (cb(null, updated));
		});
	};

	/**
	Updates the elements of the document found using the element JSON string.
	in the collection as provided by the query. The query must be a JSON string in the form :
	{ key : value }. The operator is a boolean, with true : set, and false : unset. If false is used,
	the value is ignored, but the json string still must have one.
	**/
	setElements(operator, collection, element, query, cb) {
		if (typeof operator != "boolean") return (cb("setElements: operator must be true or false"));
		let set = (operator == true) ? {$set : query} : {$unset : query};
		this.mdb.collection(collection).updateOne(element, set, (err, updatedDoc) => {
			if (err) return (cb(err));
			return (null, updatedDoc);
		})
	}

	/**
	Adds the data passed as argument to the given collection. The collection
	must be a string and the data a valid json string.
	**/
	addElements(collection, data, cb) {
		if (!Array.isArray(data)) return (cb('Data must be prived ad an array'));
		if (data.length == 0) return cb(null, []);
		this.mdb.collection(collection).insertMany(data, (err, insertedDoc) => {
			if (err) return (cb(err));
			return (cb(null, insertedDoc));
		})
	}

	closeClient() { this.client.close(); }


}

exports.Mongo = Mongo;
