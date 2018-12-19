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
Updated: 2018/12/19 14:23:08 by fsabatie
*/

import * as Commons from '../commons.js';
import * as Parameters from './parameters.js';

/**
Definition of the QuasrFunction class : must provide at least a name.
Only the functins listed as QuasrFunction will be proposed for usage.
*/
class QuasrFunction {
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
		if (!(parameter instanceof Parameters.Parameter)) Commons.__ERR(`Parameter must be of type Parameter`, Commons.__FATAL);
		// Checks if the parameter does not exist already
		if (this.parameterExists(parameter.name)) Commons.__ERR(`Parameter already exists for function ${this.name}`, Commons.__FATAL);
		// Pushes the parameter to the list
		else this.parameters.push(parameter);
	}
}

/** Creates a QuasrFunction function */
function createFunction(func) {
	// Gets the function's name
	let funcName = func.match(/(\w+|(\w+-*)*)(?=\s*\()/g);
	// Gets the function's type
	let funcType = func.match(/^(\w+\s+)*(\*\s*)*(?!\()/g); //TODO : Regex does not take types with "-" in it.
	// Parses the function's parameters
	let parameters = Parameters.parseParameters(func);
	// Checks for errors
	if (!funcName || !funcType || !parameters) return (Commons.__ERR(`Could not parse function ${func}`, Commons.__NONBLOCKING));
	// Everything went right, we build the QuasrFunction object
	func = new QuasrFunction(funcName[0], funcType[0].trim());
	// We add all the parsed parameters to the function if there are some
	if (typeof parameters == "object") for (let param of parameters) func.addParameter(param);
	// Returning the function
	return (func);
}

/** Parses all the functions and their parameters from the file content.
We parse the regular files first in order to collect all functions declarations (functions' prototypes do not always contain the variables' name, parsing functions' declarations allows us to collect both their names, as well as the type and name of their variables). We then parse header files for functions names, and only keep functions present in both header files and regular files.

A BETTER PARSING OF HEADER FILES MIGHT HELP AVOIDING THE DOUBLE PARSING OF BOTH .C AND .H FILES (although this double check brings safety, and helps making sure header files do not list non-declared functions : they can be prototyped in the header yet declared nowhere) */
function getFunctions(fileContent) {
	// Regex for the functions prototypes - used against header (.h) files
	let functionPrototypeRegex = new RegExp(/^(?!static)(\w+\s+)+\**(\w+|(\w+-*)*)(?=\s*\()\s*\((.|,\n|\n,.|(\n*\s*,.)|(\n\s*,\n*\s*)|(\n\s\n*\s*))*\);$/gm);
	// Regex for the functions prototypes - used against regular (.c) files
	let functionDeclarationRegex = new RegExp(/^(?!static)(\w+\s+)+\**(\w+|(\w+-*)*)(?=\s*\()\s*\((.|,\n|\n,.|(\n*\s*,.)|(\n\s*,\n*\s*)|(\n\s\n*\s*))*\)(\s*|\n*\s*)*\{/gm); // .c Files
	// Getting all matches for function declarations
	let functions = fileContent.match(functionPrototypeRegex);
	// Whitespacing the function declaration for parsing
	functions = functions.map((func) => { return (func.replaceAll('\t\r', ' ').replaceAll(/\s+/g, ' ')); });
	// Creating the function objects
	functions = functions.map((func) => { return (createFunction(func)) });
	return (functions);
}

export { getFunctions };
