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
Updated: 2019/02/24 15:19:35 by fsabatie
*/

const Rfr		= require('rfr');
const Files		= Rfr('controllers/programs/qr_files_ctrl.js');
const Parsers	= Rfr('controllers/programs/qr_parsers_ctrl.js');
const Rpc		= Rfr('controllers/programs/qr_rpc_builder_ctrl.js');

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
	return (new Promise((resolve, reject) => {
		Files.saveGitRepoFiles(gitInfo, __GIT_DOWNLOAD_FOLDER_PATH, (err, localRepoPath) => {
			if (err) return (callback(err));
			Parsers.parse(localRepoPath, (err, program) => {
				if (err) return (callback(err));
				__CONSOLE_DEBUG('Parsed \x1b[32m✓\x1b[0m');
				program.name = gitInfo.repo;
				Rpc.buildRpcService(__THRIFT, program, (err, service) => {
					if (err) return (callback(err));
					return (callback(null, service));
				})
			});
		})
	}));
}

exports.getProgram = getProgram;
