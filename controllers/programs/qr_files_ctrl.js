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


Filename : qr_files_ctrl.js
By: fsabatie <fsabatie@student.42.fr>
Created: 2018/12/19 20:48:34 by fsabatie
Updated: 2019/03/12 17:24:12 by fsabatie
*/

const Rfr				= require('rfr');
const Mongo				= Rfr('app_commons/qr_mongo_cm').Mongo;
// const QuasrMongo		= new Mongo(__MONGO_URL_CONNECT);
const GitDownload		= require('download-git-repo');
const Axios				= require('axios');
const Walk				= require('walk');
const Fs				= require('fs');

/**
 * Checks if the file exists
 *
 * @param {string} dirPath The path of the file
 * @param {Function} callback Callback with (bool)
 * @returns {callback}
 */
function fileExists(dirPath, callback) {
	Fs.access(dirPath, Fs.constants.F_OK, (err) => {
		if (err) return (callback(false));
		return (callback(true));
	})
}


/**
 * Saves a git repo locally
 *
 * @param {Object} gitInfo An object containing the service name (github, gitlab, bitbucket),
 * an author, and a repo.
 * @param {string} savePath The path where the repo needs to be saved
 * @param {Function} callback Callback with (err, service)
 * @returns {callback}
 */
function saveGitRepoFiles(gitInfo, savePath, callback) {
	fileExists(`${savePath}/${gitInfo.author}/${gitInfo.repo}`, (fileExists) => {
		if (fileExists) {
			__CONSOLE_DEBUG('The repository already exists \x1b[32m✓\x1b[0m');
			return (callback(null, `${savePath}/${gitInfo.author}/${gitInfo.repo}`));
		}
		if (gitInfo.service == __GITHUB) {
			__CONSOLE_DEBUG('The repository does not exist, downloading...');
			GitDownload(`${gitInfo.service}:${gitInfo.author}/${gitInfo.repo}`, `${savePath}/${gitInfo.author}/${gitInfo.repo}`, (err) => {
				if (err) return (callback(`An error occured while fetching ${gitInfo.author}/${gitInfo.repo} - ${err}`))
				__CONSOLE_DEBUG('The repository has been downloaded \x1b[32m✓\x1b[0m');
				return (callback(null, `${savePath}/${gitInfo.author}/${gitInfo.repo}`));
			})
		}
	})
}

exports.saveGitRepoFiles	= saveGitRepoFiles;
