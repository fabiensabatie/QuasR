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


Filename : qr_parsers_ctrl.js
By: fsabatie <fsabatie@student.42.fr>
Created: 2018/12/27 00:12:03 by fsabatie
Updated: 2019/03/12 16:35:40 by fsabatie
*/

const { exec }		= require('child_process');
const { spawn }		= require('child_process');
const { ObjectId } 	= require('mongodb');

const SEP		= '|SEP|';
const CTAGS_ARG	= `-R -x --kinds-C=+z --kinds-Python=+z --c-types=+p --_xformat="%F${SEP}%K${SEP}%t${SEP}%N${SEP}%s${SEP}%l${SEP}%{C.properties}${SEP}%C"`;

/**
 * Formats the ctag output line according to the chosen format described by the
 * --_xformat ctags argument
 *
 * @param {string} line the stdout line provided by ctags
 * @returns {Object} The JSON formated object
 */
function formatLine(line) {
	line = line.replace(/"/g, '').split(SEP);
	if (line[6] == 'static') return (null); // Ignoring static functions
	let tag = {
		fileName : line[0],
		kind : line[1],
		type : line[2] ? line[2].replace('typename:', '') : line[2],
		name : line[3],
		scope : line[4],
		language : line[5],
	}
	if (tag.kind == "enumerator") {
		let compact = line[7].split("=");
		if (compact.length == 2) tag.value = compact[1].replace(/,|}|;/g, '').trim();
	}
	return (tag);
}


/**
 * Keeps only the element's type, name and language
 *
 * @param {Object} e The element (a function parameter or enum value)
 * @returns {Object} The JSON formated object
 */
function formatElement(e) {
	let el = {type : e.type, name: e.name, language: e.language}
	if (e.value) el.value = e.value;
	return (el);
}

/**
 * Uses universal ctags to parse the content of the code.
 *
 * @param {string} localRepoPath, the relative path to the local folder of repository
 * @returns {Object} The program object with its functions, enums, typedefs
 */
function parse(localRepoPath, callback) {
	let parameters = [], enumerators = [], stdout = "", tags = [],
	program = { functions: [], macros: [], typedefs: [], structs: [], enums: [], _id: new ObjectId()};
	// Starts a new child process, using spawn instead of exec to recieve stdout as a stream
	__CONSOLE_DEBUG('Starting the ctags parser...');
	let parser = spawn('ctags', CTAGS_ARG.split(' '), {cwd: localRepoPath});
	// Formats the stdout buffer
	parser.stdout.setEncoding('utf8');
	// Appends to the stdout variable
	parser.stdout.on('data', (data) => { stdout = stdout.concat(data); });
	parser.stderr.on('data', (data) => { __CONSOLE_DEBUG(`stderr: ${data}`); });
	// Once ctags exited
	parser.on('close', (code) => {
		if (code !== 0) return (callback(`ctags exited with error code ${code}`));
		__CONSOLE_DEBUG('CTAGS exited correctly \x1b[32m✓\x1b[0m\nFormatting the output...');
		stdout = stdout.split('\n');
		// Creates a tag object
		for (let line of stdout) { let fLine = formatLine(line); if (fLine) tags.push(fLine); }
		// Filters the tag types
		for (let tag of tags) {
			if (tag.kind == 'function') program.functions.push(tag)
			else if (tag.kind == 'enum') program.enums.push(tag)
			else if (tag.kind == 'macro') program.macros.push(tag)
			else if (tag.kind == 'typedef') program.typedefs.push(tag)
			else if (tag.kind == 'struct') program.structs.push(tag)
			else if (tag.kind == 'parameter') parameters.push(tag)
			else if (tag.kind == 'enumerator') enumerators.push(tag)
			tag.program_id = program._id;
		}
		program.functions = program.functions.sort();
		program.enums = program.enums.sort();
		program.structs = program.structs.sort();
		program.typedefs = program.typedefs.sort();
		// Assign the members to their respective scope (parameters to functions, values of enums)
		for (let f of program.functions) f.parameters = parameters.filter((p) => (p.scope == f.name && p.fileName == f.fileName)).map((p) => (formatElement(p)));
		for (let e of program.enums) e.members = enumerators.filter((el) => (el.scope == e.name && el.fileName == e.fileName)).map((el) => (formatElement(el)));
		return (callback(null, program));
	});
}

exports.parse = parse;
