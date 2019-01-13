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


Filename : c_parser.js
By: fsabatie <fsabatie@student.42.fr>
Created: 2018/12/19 00:35:19 by fsabatie
Updated: 2019/01/12 23:59:19 by fsabatie
*/

const Rfr			= require('rfr');
const Functions		= Rfr('controllers/parsers/C/functions.js');
const Fs			= require('fs');
const ChildProcess	= require('child_process');

/** C File parsing function */
function parseFunctions(files) {
	return (new Promise((resolve, reject) => {
		let parsedFiles = 0;
		let CFiles = files.filter((file) => (file.fileExtension == 'c' || file.fileExtension == 'h'));
		let functions = {program : [], headers : []};
		for (let i = 0; i < CFiles.length; i++) {
			let timeOut = true;
			let file = CFiles[i];
			file.functions = [];
			if (file.fileExtension != 'c' && file.fileExtension != 'h') continue ;
			console.log('Parsing file', file.fileName);
			let toPush = (file.fileExtension == 'c') ? functions.program : functions.headers;
			let parserProcess = ChildProcess.fork('controllers/parsers/C/functions.js');
			if (parserProcess) {
				parserProcess.on('message', (functionsInFile) => {
					timeOut = false;
					for (let func = 0; func < functionsInFile.length; func++) {
						let quasrFunc = new Functions.C_QuasrFunction();
						quasrFunc.objConstructor(functionsInFile[func]);
						toPush.push(quasrFunc);
						file.functions.push(quasrFunc);
					}
					console.log('Got functions from', CFiles[i].fileName, 'at', parsedFiles, '/', CFiles.length - 1);
					parserProcess.kill();
					if (parsedFiles++ == CFiles.length - 1) {
						return (resolve(__RESULT(true, Functions.keepHeaderFunctionsOnly(functions))));
					}
				});
				parserProcess.send(file.content);
			}
			setTimeout(() => {
				if (!timeOut) return;
				if (parserProcess) parserProcess.kill();
				console.log('Killed', file.fileName, 'TIMEOUT');
				if (parsedFiles++ == CFiles.length - 1) {
					return (resolve(__RESULT(true, Functions.keepHeaderFunctionsOnly(functions))))
				}
			}, 10000)
		}
	}));
}

exports.parseFunctions = parseFunctions;
