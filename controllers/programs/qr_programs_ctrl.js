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
Updated: 2019/03/13 00:03:33 by fsabatie
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
function programExistsInDB(gitInfo, callback) {
	__MONGO_ACTIVE_DBS.quasr.findDocument(__MONGO_COLLECTION_PROGRAM, {gitInfo : gitInfo}, (err, foundDoc) => {
		if (err) return (callback(null, false));
		console.log(foundDoc);
		callback(null, true);
	})
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
	callback(null, 'All elements inserted');
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
function getProgram(gitInfo, callback) {
	Files.saveGitRepoFiles(gitInfo, __GIT_DOWNLOAD_FOLDER_PATH, async (err, localRepoPath) => {
		if (err) return (callback(err));
		let hash = await hashElement(localRepoPath, {folders: { exclude: ['.*', 'node_modules'] }})
		.catch(error => { return callback(error); });
		if (!hash.hash) return;
		gitInfo.hash = hash.hash;
		console.log('Got the hash', hash.hash);
		programExistsInDB(gitInfo, (err, exists) => {
			if (err) return (callback(err));
			if (exists) return callback(null, `${__SERVICE_PATH}/${gitInfo.repo}.thrift`);
			Parsers.parse(localRepoPath, (err, program) => {
				if (err) return (callback(err));
				// Files.deleteDir(localRepoPath, (err) => {
					// if (err) return (callback(err));
					// __CONSOLE_DEBUG('Parsed the content, deleted the repo directory \x1b[32m✓\x1b[0m');
					program.gitInfo = gitInfo;
					insertProgramToDB(program, (err, result) => {
						if (err) return (callback(err));
						console.log(result);
						Rpc.buildRpcService(__THRIFT, program, (err, service) => {
							if (err) return (callback(err));
							return (callback(null, service));
						})
					})
				// })
			});
		})
	})
}

exports.getProgram = getProgram;
