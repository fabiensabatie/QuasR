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


Filename : parameters.js
By: fsabatie <fsabatie@student.42.fr>
Created: 2018/12/19 00:27:37 by fsabatie
Updated: 2018/12/19 23:55:15 by fsabatie
*/

/** Parameter class declaration : must provide a least a name */
class Parameter {
	constructor(name, type = null) {
		if (!name) return (Commons.__ERR('Please provide a name for the parameter.', Commons.__FATAL))
		this.name = name;
		this.type = type;
	}
}

/** Creates a parameter object */
function createParameter(parameter) {
	// Splitting the parameter content in order to obtain the type on one side, and the name on the other
	parameter = parameter.split(' ');
	// The last element of the splitted array is the parameter's name
	let parameterName = parameter.pop();
	// The functions takes an unknow number of parameters, we return the parameter
	if (parameterName == "...") return (new Parameter("..."));
	// Builds the type of the parameter by joining all remaining words in the parameter's content
	let parameterType = parameter.join(' ');
	// Checks if there are any pointer signs in the parameter's name
	let pointers = parameterName.match(/\*/g) || [];
	// Adds the pointer signs to the parameter's type
	for (let p in pointers) parameterType = parameterType.concat('*');
	// Removes all '*' in the parameter's name as they now are in the parameter's type
	parameterName = parameterName.replaceAll(/\*/g, '');
	// Returning the parameter
	return (new Parameter(parameterName, parameterType));
}

/** Parsing the parameter with given function */
function parseParameters(func) {
	// Gathers what is between the parentheses (the parameters)
	let paramString = func.match(/\((.*?)\)/);
	if (paramString && paramString[0] == '()') return (true);
	// Checks if there was a match
	if (!paramString || !paramString[1]) return (Commons.__ERR(`Could not parse parameter from ${func}`, Commons.__NONBLOCKING));
	// Spliting the parameters list
	let params = paramString[1].split(',');
	// Creates the parameter object for each parameter
	params = params.map((param) => createParameter(param.trim()));
	// Returns the parameters
	return (params);
}

exports.Parameter = Parameter;
exports.parseParameters = parseParameters;
