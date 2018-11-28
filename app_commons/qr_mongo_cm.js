/**

| |                | |   | |  (_) |
| |_ ___  __ _  ___| |__ | | ___| |_
| __/ _ \/ _` |/ __| '_ \| |/ / | __|
| ||  __/ (_| | (__| | | |   <| | |_
 \__\___|\__,_|\___|_| |_|_|\_\_|\__|

 * @Author: Fabien Sabatié <fabiensabatie>
 * @Date:   2018-07-09T17:27:05+02:00
 * @Email:  fsabatie@student.42.fr
 * @Filename: tck_mongo_cm.js
 * @Last modified by:   danielsaadia
 * @Last modified time: 2018-09-05T15:41:57+02:00
**/

const Rfr			= require('rfr');
const Tck			= Rfr('app.js');
const Mongo			= require('mongodb');
const PromiseResult = Rfr('app_commons/qr_promises_cm.js').promiseResult;
const JsonObjects	= Rfr('app_commons/qr_our_functions_cm.js').jsonObjects;

function stringIdize(umid) {
	if (typeof umid != 'string')
		return umid.toString();
	let umidArr = umid.split('_');
	return umidArr[umidArr.length - 1];
}
exports.stringIdize = stringIdize;

function sameId(umid1, umid2) {
	return (stringIdize(umid1) == stringIdize(umid2));
}
exports.sameId = sameId;

function refIdize(umid, refPrefix) {
	let ret = umid;
	if (typeof umid == 'string' && umid.charAt(3) != '_')
		ret = refPrefix + '_' + umid;
	else
		ret = refPrefix + '_' + umid.toString();
	return ret;
}
exports.refIdize = refIdize;

function objectIdize(umid) {
	if (typeof umid != 'string')
		return umid;
	let ret;
	let umidArr = umid.split('_');
	let goodUmid = umidArr[umidArr.length - 1];
	if (Mongo.ObjectID.isValid(goodUmid) == false)
		return false;
	return Mongo.ObjectID(goodUmid);
}
exports.objectIdize = objectIdize;

/**
Gets the mongo client and returns it in the 'result' field of a promise result object
(see app_commons/pm_promises.js).
**/
function getMongoClient() {
	return (new Promise((resolve, reject) => {
		let mongo_client = Mongo.MongoClient;
		mongo_client.connect(__MONGO_URL, { useNewUrlParser: true }, (err, client) => {
			if (err) { return (reject(PromiseResult(false, {}, err))) }
			return (resolve(PromiseResult(true, {mdb : client.db(__MONGO_DBNAME), client : client})))
		});
	}));
}

/**
Get all the documents from collection
**/
function getCollection(collectionName) {
	return (new Promise((resolve, reject) => {
		getMongoClient()
		.then((ret) => {
			ret.result.mdb.collection(collectionName).find({}).toArray(function(err, collec) {
				ret.result.client.close();
				if (err) { return (reject(PromiseResult(false, {}, err))); }
				return (resolve(PromiseResult(true, collec)));
			  });
		})
		.catch((err) => { return (reject(PromiseResult(false, {}, err.error))); });
	}));
}

/**
Get all the documents from collection with JSON parameter. The collection
must be a string and the data a valid json string.
**/
function getDocuments(collectionName, params) {
	if (params._id) params._id = objectIdize(params._id);
	if (params.length)
		for (var i = 0; i < params.length; i++) if (params[i]._id) params[i]._id = objectIdize(params[i]._id);
	return (new Promise((resolve, reject) => {
		getMongoClient()
		.then((ret) => {
			ret.result.mdb.collection(collectionName).find(params).toArray(function(err, collec) {
				ret.result.client.close();
				if (err) {return (reject(PromiseResult(false, {}, err)));}
				if (collec.length < 1) {return (reject(PromiseResult(false, {}, "No document was found")));}
				return (resolve(PromiseResult(true, collec)));
			});
		})
		.catch((err) => { return (reject(PromiseResult(false, {}, err.error))); });
	}));
}


/**
Adds the data passed as argument to the given collection. The collection
must be a string and the data a valid json string.
**/
function addElements(collection, data) {
	return (new Promise((resolve, reject) => {
		getMongoClient()
		.then((ret) => {
			ret.result.mdb.collection(collection).insert(data, (err, insertedDoc) => {
				ret.result.client.close();
				if (err) { return (reject(PromiseResult(false, {}, err))); }
				return (resolve(PromiseResult(true, insertedDoc)));
			})
		})
		.catch((err) => { return (reject(PromiseResult(false, {}, err.error))); });
	}));
}

/**
Finds a document in the collection given, and returns it. The data must be a valid JSON string,
and using the _id to find the document implies that _id is a mongodb ObjectID object.
**/
function findDocument(collection, data) {
	if (data._id) data._id = objectIdize(data._id);
	return (new Promise((resolve, reject) => {
		getMongoClient()
		.then((ret) => {
			ret.result.mdb.collection(collection).findOne(data, (err, foundDoc) => {
				if (err) { return (reject(PromiseResult(false, {}, err))) }
				if (foundDoc == null || foundDoc == []) {
					if (collection == __MONGO_USERSCOLLECTION) {
						ret.result.mdb.collection(collection).findOne({email: 'none@none.none'}, (err, unknowUser) => {
							ret.result.client.close();
							return (resolve(PromiseResult(true, unknowUser)));
						})
					} else {
						ret.result.client.close();
						return (reject(PromiseResult(false, {}, "Could not find the document"))) };
					}
				else {
					ret.result.client.close();
					return (resolve(PromiseResult(true, foundDoc)));
				}
			})
		})
		.catch((err) => { return (reject(PromiseResult(false, {}, err.error))); });
	}))
}

/**
Change the doc matching with docSpecs with doc replace, only _id stays
**/
function updateWithNew(collection, docSpecs, docReplace, options = {}) {
	if (docSpecs._id) docSpecs._id = objectIdize(docSpecs._id);
	return (new Promise((resolve, reject) => {
		getMongoClient()
		.then((ret) => {
			ret.result.mdb.collection(collection).update(docSpecs, docReplace, options, (err, updated) => {
				if (err || updated == null || !updated) {
					return (reject(PromiseResult(false, {}, err)))
				}
				else {
					ret.result.client.close();
					return (resolve(PromiseResult(true, updated)));
				}
			})
		})
		.catch((err) => { return (reject(PromiseResult(false, {}, err.error))); });
	}))
}
exports.updateWithNew = updateWithNew;

/**
Finds a document in the collection given, and returns the element of this document defined by the
element argument. The data must be a valid JSON string, and using the _id to find the document
implies that _id is a mongodb ObjectID object.
The element must be a string. If no element is passed, the whole document is returned.
**/
function getDocumentElement(collection, data, element = 'all') {
	if (data._id) data._id = objectIdize(data._id);
	return (new Promise((resolve, reject) => {
		findDocument(collection, data)
		.then((ret) => { return (resolve((element != 'all') ?
		PromiseResult(true, ret.result[element]) : PromiseResult(true, ret.result))); })
		.catch((err) => { return (reject(PromiseResult(false, {}, err.error))) })
	})
)}

/**
Finds a document in the collection given, and returns the elements of this document defined by the
elements argument. The data must be a valid JSON string, and using the _id to find the document
implies that _id is a mongodb ObjectID object.
elements must be an array. If no element is passed, the whole document is returned.
**/
function getDocumentElements(collection, data, elements) {
	if (data._id) data._id = objectIdize(data._id);
	return (new Promise((resolve, reject) => {
		findDocument(collection, data)
		.then((ret) => {
			let result = {};
			for (let i = 0; i < elements.length; i++)
				result[elements[i]] = ret.result[elements[i]];
			return (resolve(PromiseResult(true, result)))})
		.catch((err) => { return (reject(PromiseResult(false, {}, err.error))) })
	}))
}

/**
Finds a document in the collection given, and returns the nested element of this document defined by
the jsonArrPath argument. The data must be a valid JSON string, and using the _id to find the
document implies that _id is a mongodb ObjectID object. jsonArrPath is an array describing the path
to the nested element (e.g ['user','name'] for user.name). If no jsonArrPath is passed,
the whole document is returned.
**/
function getDocumentNestedElement(collection, data, jsonArrPath) {
	return (new Promise((resolve, reject) => {
		findDocument(collection, data)
		.then((ret) => {
			let result = JsonObjects.getObjByArrPath(ret.result, jsonArrPath);
			return (resolve(PromiseResult(true, result)))})
		.catch((err) => { return (reject(PromiseResult(false, {}, err.error))) })
	}))
}

/**
Finds a document in the collection given, and returns the nested elements of this document defined
by the jsonArrPaths argument. The data must be a valid JSON string, and using the _id to find the
document implies that _id is a mongodb ObjectID object. jsonArrPaths is an array of arrays
describing the path to the nested element. If no jsonArrPaths is passed, the whole document is
returned.
**/
function getDocumentNestedElements(collection, data, jsonArrPaths) {
	return (new Promise((resolve, reject) => {
		findDocument(collection, data)
		.then((ret) => {
			let result = {};
			for (let i = 0; i < jsonArrPaths.length; i++)
				result[jsonArrPaths[i][jsonArrPaths[i].length - 1]] = JsonObjects.getObjByArrPath(ret.result, jsonArrPaths[i]);
			return (resolve(PromiseResult(true, result)))})
		.catch((err) => { return (reject(PromiseResult(false, {}, err.error))) })
	}))
}

/**
Pushed the data to an element in the collection given, and returns the pushed element.
The element must be a valid JSON string, and using the _id to find the document
implies that _id is a mongodb ObjectID object. The data must be a valid JSON string.
**/
function pushDataToElement(collection, element, data) {
	if (element._id) element._id = objectIdize(element._id);
	return (new Promise((resolve, reject) => {
		getMongoClient()
		.then((ret) => {
			ret.result.mdb.collection(collection).findOneAndUpdate(element, {$push : data}, {returnOriginal : false}, (err, inserted) => {
				ret.result.client.close();
				if (err) { return (reject(PromiseResult(false, {}, err))) }
				else {
					return (resolve(PromiseResult(true, inserted)));
				}
			});
		})
		.catch((err) => { return (reject(PromiseResult(false, {}, err.error))) });
	}));
};


/**
Adds the values contained in the data array to the element defined by setName.
This function is a copy of pushDataToElement, except it does nothing if the value is already in the array.
**/
function addEachToSet(collection, element, setName, data) {
	if (element._id) element._id = objectIdize(element._id);
	return (new Promise((resolve, reject) => {
		if (typeof(data) != 'object') return (reject(PromiseResult(false, {}, 'Data must be an array')));
		getMongoClient()
		.then((ret) => {
			let query = {};
			query[setName] = {$each : data}
			ret.result.mdb.collection(collection).findOneAndUpdate(element, {$addToSet : query}, (err, updated) => {
				ret.result.client.close();
				if (err) { return (reject(PromiseResult(false, {}, err))) }
				else {
					return (resolve(PromiseResult(true, updated)));
				}
			});
		})
		.catch((err) => { return (reject(PromiseResult(false, {}, err.error))) });
	}));
};


/**
Updates the document found using the docSpecs JSON string in the collection
as provided by toUpdate. toUpdate must be a JSON string in the form :
{ key : value }. original is a boolean, with true : return the old doc,
and false : return the updated one.
**/
let updateDocAndReturn = function(collection, docSpecs, toUpdate, original = false) {
	if (docSpecs._id) docSpecs._id = objectIdize(docSpecs._id);
	return (new Promise((resolve, reject) => {
		getMongoClient()
		.then((suc) => {
			let mdb = suc.result.mdb;
			let mongoClient = suc.result.client;
			mdb.collection(collection).findOneAndUpdate(docSpecs, {$set : toUpdate},
			{returnOriginal : original}, (err, doc) => {
				mongoClient.close();
				if (err) return (reject(PromiseResult(false, {}, err)));
				return (resolve(PromiseResult(true, doc)));
			});
		})
		.catch((err) => {
			return (reject(PromiseResult(false, {}, err.error)))
		})
	}));
};

/**
Updates the document found using the docSpecs JSON string in the collection
using the mongo json toUpdate. toUpdate must be a valid mongo json string.
original is a boolean, with true : return the old doc,
and false : return the updated one.
**/
let genUpdateDocAndReturn = function(collection, docSpecs, toUpdate, original = false) {
	if (docSpecs._id) docSpecs._id = objectIdize(docSpecs._id);
	return (new Promise((resolve, reject) => {
		getMongoClient()
		.then((suc) => {
			let mdb = suc.result.mdb;
			let mongoClient = suc.result.client;
			mdb.collection(collection).findOneAndUpdate(docSpecs, toUpdate,
			{returnOriginal : original}, (err, doc) => {
				mongoClient.close();
				if (err) return (reject(PromiseResult(false, {}, err)));
				return (resolve(PromiseResult(true, doc)));
			});
		})
		.catch((err) => {
			return (reject(PromiseResult(false, {}, err.error)))
		})
	}));
};
exports.genUpdateDocAndReturn = genUpdateDocAndReturn;

/**
Updates the elements of the document found using the element JSON string.
in the collection as provided by the query. The query must be a JSON string in the form :
{ key : value }. The operator is a boolean, with true : set, and false : unset. If false is used,
the value is ignored, but the json string still must have one.
**/
function setElements(operator, collection, element, query) {
	if (element._id) element._id = objectIdize(element._id);
	console.log(collection, element);
	return (new Promise((resolve, reject) => {
		let keys = Object.keys(element);
		for (let i = 0; i < keys.length ; i++) if (keys[i] == '_id' && keys['_id'] == false) return (reject(PromiseResult(false, {}, "Invalid id")));
		findDocument(collection, element)
		.then(() => {
			getMongoClient()
			.then((ret) => {
				if (operator == true) {
					ret.result.mdb.collection(collection).updateOne(element,
					{$set : query}, (err, updatedDoc) => {
						ret.result.client.close();
						if (err) { return (reject(PromiseResult(false, {}, err)))}
						return (resolve(PromiseResult(true, updatedDoc)))
					})
				} else if (operator == false){
					ret.result.mdb.collection(collection).updateOne(element,
					{$unset : query}, (err, updatedDoc) => {
						ret.result.client.close();
						if (err) { return (reject(PromiseResult(false, {}, err))) }
						return (resolve(PromiseResult(true, updatedDoc)))
					})
				}
				else
					return (reject(PromiseResult(false, {},
					"setElements: operator must be true or false")))
			}).catch((err) => { return (reject(PromiseResult(false, {}, err.error))); });
		}).catch((err) => { return (reject(PromiseResult(false, {}, err.error))); });
	}))
}

/**
Removes the document found using the query. Query must be a valid JSON string. If using the _id
to find the document implies that _id is a mongodb ObjectID object.
**/
function deleteDocument(collection, query) {
	if (query._id) query._id = objectIdize(query._id);
	return (new Promise((resolve, reject) => {
		getMongoClient()
		.then((ret) => {
			ret.result.mdb.collection(collection).deleteMany(query, (err, removedDoc) => {
				ret.result.client.close();
				if (err) { return (reject(PromiseResult(false, {}, err)))}
				return (resolve(PromiseResult(true, removedDoc)))
			})
		})
		.catch((err) => { return (reject(PromiseResult(false, {}, err.error))); });
	}))
}

/**
Removes one or all elements in a doc array matching the data specs.
Eg : pullElement('users', {_id : 1234}, {pets : {'type' : 'dog'}}, true)
-> Removes all dogs of the user 1234 (if set to false, only the first dog is removed)
**/
function pullElement(collection, docSpecs, data, multi = true) {
	if (docSpecs._id) docSpecs._id = objectIdize(docSpecs._id);
	return (new Promise((resolve, reject) => {
		getMongoClient()
			.then((ret) => {
				let query = {$pull : data};
				ret.result.mdb.collection(collection).updateOne(docSpecs, query, {multi : multi},
				(err, updated) => {
					ret.result.client.close();
					if (err) {
						return (reject(PromiseResult(false, {}, err)))
					} else {
						return (resolve(PromiseResult(true, updated)))
					}
				});
			})
			.catch((err) => {
				return (reject(PromiseResult(false, {}, err.error)))
			});
	}))
};

exports.getCollection				= getCollection;
exports.getDocuments				= getDocuments;
exports.setElements					= setElements;
exports.addElements					= addElements;
exports.addDocument					= addElements;
exports.deleteDocument				= deleteDocument;
exports.getMongoClient				= getMongoClient;
exports.findDocument				= findDocument;
exports.getDocumentElement			= getDocumentElement;
exports.getDocumentElements			= getDocumentElements;
exports.pushDataToElement			= pushDataToElement;
exports.getDocumentNestedElement	= getDocumentNestedElement;
exports.getDocumentNestedElements	= getDocumentNestedElements;
exports.updateDocAndReturn			= updateDocAndReturn;
exports.pullElement					= pullElement;
exports.addEachToSet				= addEachToSet;
