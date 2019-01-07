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


Filename : qr_programs_ctrl.js
By: fsabatie <fsabatie@student.42.fr>
Created: 2018/12/27 00:12:03 by fsabatie
Updated: 2019/01/06 19:48:13 by fsabatie
*/

const Rfr		= require('rfr');
const Axios		= require('axios');
const Files		= Rfr('controllers/files/qr_files_ctrl.js');
const Parsers	= Rfr('controllers/parsers/qr_parsers_ctrl.js').Parsers;
const Builders	= Rfr('controllers/builders/qr_builders_ctrl.js').Builders;

class QuasR_Program {
	constructor(name, author, service, language, files = [], availableFunctions = []) {
		this.name				= name;
		this.author				= author;
		this.service			= service;
		this.files				= files;
		this.availableFunctions	= availableFunctions;
		this.language			= language;
	}

	build() {
		Builders[this.language](this);
	}
}

function getProgramLanguages(gitInfo) {
	return (new Promise((resolve, reject) => {
		if (gitInfo.service == __GITHUB) {
			Axios.get(`https://api.github.com/repos/${gitInfo.author}/${gitInfo.repo}/languages`)
			.then((result) => {
				if (result.data && Object.keys(result.data).length) return (resolve(__RESULT(true, Object.keys(result.data))));
				return (reject(__RESULT(false, 'No languages were found.')));
			}).catch((err) => { return (reject(__RESULT(false, `An error occured while fetching languages for ${gitInfo.author}/${gitInfo.repo} - ${err}`))); })
		}
	}))
}

function getProgram(gitInfo) {
	return (new Promise((resolve, reject) => {
		getProgramLanguages(gitInfo)
		.then((lresponse) => {
			let mainLanguage = lresponse.result[0];
			Files.saveGitRepoFiles(gitInfo, `${__GIT_DOWNLOAD_FOLDER_PATH}/${mainLanguage}`)
			.then((localRepoPath) => {
				localRepoPath = localRepoPath.result;
				Files.getFileListFromPath(localRepoPath, (filesPaths) => {
					Files.getFilesContent(filesPaths)
					.then((files) => {
						files = files.result;
						let availableFunctions = Parsers.C(files);
						let program = new QuasR_Program(gitInfo.repo, gitInfo.author, gitInfo.service, mainLanguage, files, availableFunctions);
						return (resolve(__RESULT(true, program)));
					})
				})
			})
		}).catch((err) => { return (reject(__RESULT(false, err))); })
	}));
}

setTimeout(() => {
	let gitInfo = {
		service : __GITHUB,
		author : 'uael',
		repo : 'ft_malloc'
	};
	getProgram(gitInfo)
	.then((program) => {
		program = program.result;
		console.log(`\nParsed ${program.name} from ${program.author}, written in ${program.language}, containing ${program.availableFunctions.length} functions within ${program.files.length} files.`);
		program.build();
	})
}, 1000);

exports.getProgram = getProgram;
