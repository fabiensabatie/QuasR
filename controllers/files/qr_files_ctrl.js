/**
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
Updated: 2018/12/27 00:56:42 by fsabatie
*/

const Rfr				= require('rfr');
const Mongo				= Rfr('app_commons/qr_mongo_cm').Mongo;
const QuasrMongo		= new Mongo(__MONGO_URL);
const Parsers			= Rfr('controllers/parsers/qr_parsers_ctrl.js').PARSERS;
const GitDownload		= require("download-git-repo");
const Axios				= require('axios');
const Walk				= require('walk');
const Fs				= require('fs');

function getFileContent(filePath) {
	return (new Promise((resolve, reject) => {
		if (!filePath) return (reject(__RESULT(false, 'Please provide a file path')));
		Fs.readFile(filePath, 'utf8', (err, data) => {
			if (err) return (reject(__RESULT(false, `Could not read the file : ${err}`)));
			return (resolve(__RESULT(true, data)));
		})
	}))
}

function getFilesContent(filesPaths) {
	return (new Promise((resolve, reject) => {
		let filesContents = [];
		let asyncFunc = async function() {
			for (let i = 0; i < filesPaths.length; i++) {
				let fileContent = await getFileContent(filesPaths[i])
				.catch((err) => (reject(__RESULT(false, err))))
				if (!fileContent) return ;
				let file = {
					path : filesPaths[i],
					fileName : filesPaths[i].split('/').pop(),
					fileExtension : filesPaths[i].split('/').pop().split('.').pop(),
					content : fileContent.result,
				};
				filesContents.push(file);
			}
			return (resolve(__RESULT(true, filesContents)));
		}
		asyncFunc();
	}))
}

function getFileListFromPath(path, callback) {
	let filesPaths = [], walker = Walk.walk(path, { followLinks: false });
	walker.on('file', function(root, stat, next) { filesPaths.push(root + '/' + stat.name); next(); });
	walker.on('end', function() { callback(filesPaths); });
}

/**
Home page page GET method.
**/
function saveGitRepoFiles(gitInfo, savePath) {
	return (new Promise((resolve, reject) => {
		if (gitInfo.service == __GITHUB) {
			GitDownload(`${gitInfo.service}:${gitInfo.author}/${gitInfo.repo}`, `${savePath}/${gitInfo.author}/${gitInfo.repo}`, (err) => {
				if (err) return (reject(__RESULT(false, `An error occured while trying to fetch ${gitInfo.author}/${gitInfo.repo} - ${err}`)));
				return (resolve(__RESULT(true, `${savePath}/${gitInfo.author}/${gitInfo.repo}`)));
			})
		}
	}))
}

exports.saveGitRepoFiles	= saveGitRepoFiles;
exports.getFileListFromPath	= getFileListFromPath;
exports.getFilesContent		= getFilesContent;
