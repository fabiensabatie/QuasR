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


Filename : functions.js
By: fsabatie <fsabatie@student.42.fr>
Created: 2018/12/19 00:27:37 by fsabatie
Updated: 2018/12/27 22:55:49 by fsabatie
*/

const Rfr			= require('rfr');
const Parameters	= Rfr('controllers/parsers/C/parameters.js');
const Assert		= require('assert');

/**
Definition of the C_QuasrFunction class : must provide at least a name.
Only the functions listed as C_QuasrFunction will be proposed for usage.
*/
class C_QuasrFunction {
	constructor(name, returnType = null) {
		this.name = name;
		this.returnType = returnType;
	}

	/** Checks if the parameter is already listed in the function's parameters */
	parameterExists(parameterName) {
		for (let param of this.parameters)
			if (param.name == parameterName) return (true);
		return (false);

	}

	/** Adds a parameter to the function's parameters */
	addParameter(parameter) {
		// Creating the parameters array if non-existant
		if (!this.parameters) this.parameters = [];
		// Checks if the parameter is a parameter object
		if (!(parameter instanceof Parameters.Parameter)) __ERR(`Parameter must be of type Parameter`, __FATAL);
		// Checks if the parameter does not exist already
		if (this.parameterExists(parameter.name)) __ERR(`Parameter already exists for function ${this.name}`, __FATAL);
		// Pushes the parameter to the list
		else this.parameters.push(parameter);
	}

	/** Compare the current function to another one */
	isEqualToFunction(func) {
		// Checks if function has the correct type
		if (!(func instanceof C_QuasrFunction)) return (__ERR(`The object is not a C_QuasrFunction`, __NONBLOCKING));
		if (this.name != func.name) return (false);
		// Checks parameters
		for (let i in this.parameters)
			if (!this.parameters[i].isEqualToParameter(func.parameters[i]))
			{
				process.stdout.write(" ");
				process.stdout.write(this.parameters[i].type);
				process.stdout.write(" different from ");
				process.stdout.write(func.parameters[i].type);
				return (false);
			}
		return (true);
	}
}

function keepHeaderFunctionsOnly(functions) {
	let availableFunctions = [];
	for (let cFunc of functions.program) {
		process.stdout.write(cFunc.name);
		process.stdout.write(' \x1b[33m•\x1b[0m');
		for (let hFunc of functions.headers)
			if (cFunc.isEqualToFunction(hFunc)) {
				availableFunctions.push(cFunc);
				process.stdout.write(' \x1b[32m✔\x1b[0m');
			}
		console.log('');
	}
	return (availableFunctions);
}

/** Creates a C_QuasrFunction function */
function createFunction(func) {
	// Gets the function's name
	let funcName = func.match(/(\w+|(\w+-*)*)(?=\s*\()/g);
	// Gets the function's type
	let funcType = func.match(/^(\w+\s+)*(\*\s*)*(?!\()/g); //TODO : Regex does not take types with "-" in it.
	// Parses the function's parameters
	let parameters = Parameters.parseParameters(func);
	// Checks for errors
	if (!funcName || !funcType || !parameters) return (Commons.__ERR(`Could not parse function ${func}`, Commons.__NONBLOCKING));
	// Everything went right, we build the C_QuasrFunction object
	func = new C_QuasrFunction(funcName[0], funcType[0].trim());
	// We add all the parsed parameters to the function if there are some
	if (typeof parameters == "object") for (let param of parameters) func.addParameter(param);
	// Returning the function
	return (func);
}

/** Parses all the functions and their parameters from the file content. */
function getFunctions(fileContent) {
	// Regex for the functions prototypes - used against header (.h) files
	let functionPrototypeRegex = new RegExp(/^(?!static)(\w+\s+)+\**(\w+|(\w+-*)*)(?=\s*\()\s*\((.|,\n|\n,.|(\n*\s*,.)|(\n\s*,\n*\s*)|(\n\s\n*\s*))*\);$/gm);
	// Regex for the functions prototypes - used against regular (.c) files
	let functionDeclarationRegex = new RegExp(/^(?!static)(\w+\s+)+\**(\w+|(\w+-*)*)(?=\s*\()\s*\((.|,\n|\n,.|(\n*\s*,.)|(\n\s*,\n*\s*)|(\n\s\n*\s*))*\)(\s*|\n*\s*)*\{/gm); // .c Files
	let functions = fileContent.match(functionPrototypeRegex);
	if (!functions) functions = fileContent.match(functionDeclarationRegex);
	if (!functions) return [];
	// Whitespacing the function declaration for parsing
	functions = functions.map((func) => { return (func.replaceAll('\t\r', ' ').replaceAll(/\s+/g, ' ')); });
	// Creating the function objects
	functions = functions.map((func) => { return (createFunction(func)) });
	return (functions);
}

exports.getFunctions = getFunctions;
exports.keepHeaderFunctionsOnly = keepHeaderFunctionsOnly;