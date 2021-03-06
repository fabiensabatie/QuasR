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


Filename : qr_programs_ctrl.js
By: fsabatie <fsabatie@student.42.fr>
Created: 2018/12/27 00:12:03 by fsabatie
Updated: 2019/05/22 01:11:12 by fsabatie
*/

const Rfr		= require('rfr');
const Files		= Rfr('controllers/programs/qr_files_ctrl.js');
const Parsers	= Rfr('controllers/programs/qr_parsers_ctrl.js');
const Rpc		= Rfr('controllers/programs/qr_rpc_builder_ctrl.js');
const Crypto	= require('crypto');
const { hashElement } = require('folder-hash');

/**
 * Checks if the repo already exists in DB
 *
 * @param {Object} gitInfo An object containing the service name (github, gitlab, bitbucket),
 * an author, and a repo.
 * @param {Function} callback Callback with (err, result)
 * @returns {callback}
 */
function programExistsInDB(gitInfo) {
	return (new Promise((resolve, reject) => {
		__MONGO_ACTIVE_DBS.quasr.findDocument(__MONGO_COLLECTION_PROGRAM, {gitInfo : gitInfo}, (err, foundDoc) => {
			if (err) return resolve(false);
			return resolve(true);
		})
	}))
}

/**
 * Downloads the git repo required, parses the content, and builds the RPC service
 * for the parsed code.
 *
 * @param {Object} gitInfo An object containing the service name (github, gitlab, bitbucket),
 * an author, and a repo.
 * @param {Function} callback Callback with (err, service)
 * @returns {callback}
 */
function insertProgramToDB(program, callback) {
	return (Promise.resolve())
	// let pData = {_id : program._id, gitInfo: program.gitInfo};
	// __MONGO_ACTIVE_DBS.quasr.addElements(__MONGO_COLLECTION_PROGRAM, [pData], (err) => {
	// 	if (err) return (callback(err));
	// 	__MONGO_ACTIVE_DBS.quasr.addElements(__MONGO_COLLECTION_FUNCTION, program.functions, (err) => {
	// 		if (err) return (callback(err));
	// 		__MONGO_ACTIVE_DBS.quasr.addElements(__MONGO_COLLECTION_ENUM, program.enums, (err) => {
	// 			if (err) return (callback(err));
	// 			__MONGO_ACTIVE_DBS.quasr.addElements(__MONGO_COLLECTION_TYPEDEF, program.typedefs, (err) => {
	// 				if (err) return (callback(err));
	// 				__MONGO_ACTIVE_DBS.quasr.addElements(__MONGO_COLLECTION_STRUCT, program.structs, (err) => {
	// 					if (err) return (callback(err));
	// 					return (callback(null, 'All elements inserted'));
	// 				})
	// 			})
	// 		})
	// 	})
	// })
}

/**
 * Downloads the git repo required, parses the content, and builds the RPC service
 * for the parsed code.
 *
 * @param {Object} gitInfo An object containing the service name (github, gitlab, bitbucket),
 * an author, and a repo.
 * @param {Function} callback Callback with (err, service)
 * @returns {callback}
 */
function getProgram(gitInfo, cache = {}) {
	return Files.saveGitRepoFiles(gitInfo, __GIT_DOWNLOAD_FOLDER_PATH)
	.then((localRepoPath) => { cache.localRepoPath = localRepoPath;
		return hashElement(localRepoPath, {folders: { exclude: ['.*', 'node_modules'] }}) })
	.then((hash) => { gitInfo.hash = hash.hash; return programExistsInDB(gitInfo) })
	.then((exists) => {
		if (exists) return (Promise.resolve(`${__SERVICE_PATH}/${gitInfo.repo}.thrift`));
		return Parsers.parse(cache.localRepoPath)})
	.then((program) => {
		program.gitInfo = gitInfo;
		program.missingInfo = {
			types : [
				{type: 'parameter', name: 'str', function: 'ft_strlen'},
				{type: 'parameter', name: 'str', function: 'ft_strcpy'},
				{type: 'function' , name: 'ft_strcpy'},
			]
		}
		if (!program.missingInfo) return insertProgramToDB(program);
		return Promise.resolve(program)})
	.then((program) => {
		if (!program.missingInfo) return Rpc.buildRpcService(__THRIFT, program)
		return Promise.resolve(program)
	})
}

function api_getProgram(req, res) {
	getProgram(req.body)
	.then((program) => {
		console.log('Got a program with', program);
		console.log(program.missingInfo);
		if (program.missingInfo) {
			return res.status(200).send(JSON.stringify(program))
		}
		console.log('Returning service file to user: ' + program);
		return res.status(200).send(program);
	})
	.catch((err) => { return res.status(501).send(err); })
}

exports.getProgram     = getProgram;
exports.api_getProgram = api_getProgram;
