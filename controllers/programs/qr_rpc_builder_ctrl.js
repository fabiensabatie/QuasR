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


Filename : qr_rpc_builder_ctrl.js
By: fsabatie <fsabatie@student.42.fr>
Created: 2018/12/27 00:12:03 by fsabatie
Updated: 2019/02/25 22:16:04 by fsabatie
*/

const Fs = require('fs');
const THRIFT_TYPES = {
	C : {
		byte : ['int8_t', 'uint8_t', 'int_least8_t', 'uint_least8_t', 'int_fast8_t', 'char'],
		i16 : ['int16_t', 'uint16_t', 'int_least16_t', 'uint_least16_t', 'int_fast16_t'],
		i32 : ['int32_t', 'uint32_t', 'int_least32_t', 'uint_least32_t', 'int_fast32_t', 'int', 'long', 'unsigned long'],
		i64 : ['int64_t', 'uint64_t', 'int_least64_t', 'uint_least64_t', 'int_fast64_t', 'size_t'],
		double : ['double', 'float'],
		string : ['char *'],
		void : ['void']
	},
	"C++" : {
		byte : ['int8_t', 'uint8_t', 'int_least8_t', 'uint_least8_t', 'int_fast8_t', 'char'],
		i16 : ['int16_t', 'uint16_t', 'int_least16_t', 'uint_least16_t', 'int_fast16_t'],
		i32 : ['int32_t', 'uint32_t', 'int_least32_t', 'uint_least32_t', 'int_fast32_t', 'int', 'long', 'unsigned long'],
		i64 : ['int64_t', 'uint64_t', 'int_least64_t', 'uint_least64_t', 'int_fast64_t'],
		double : ['double', 'float'],
		string : ['char *'],
		void : ['void']
	}
}

/**
 * Gets the type from the custom typedefs, enums, macros or structs from the user's code
 *
 * @param {Object} program The program variable
 * @param {string} type The tag type
 * @returns {Object} The corresponding type or null
 */
function __get_corresponding_custom_type(program, type) {
	for (let typedef of program.typedefs) if (typedef.name == type) return (typedef.name);
	for (let member of program.enums) if (member.name == type) return (member.name);
	for (let macro of program.macros) if (macro.name == type) return (macro.name);
	for (let struct of program.structs) if (struct.name == type) return (struct.name);
	return (null);
}

/**
 * Gets the type from the thrift types object
 *
 * @param {string} type The tag type
 * @param {string} language The tag language
 * @returns {Object} The corresponding type or null
 */
function __get_corresponding_thrift_type(type, language) {
	if (!THRIFT_TYPES[language]) return (null);
	let t_types = Object.keys(THRIFT_TYPES[language]);
	for (let t_type of t_types) if (THRIFT_TYPES[language][t_type].includes(type)) return (t_type);
	return (null);
}

/**
 * Gets the element type (for functions, parameters, and constants)
 *
 * @param {Object} func The program function
 * @returns {Object} The JSON formated object or null
 */
function __get_type(program, type, language) {
	return (__get_corresponding_thrift_type(type.replace(/ const/g, ''), language) // regex filters pointers and const out
	|| __get_corresponding_custom_type(program, type.replace(/ const/g, '')) || 'binary');
}

/**
 * Keeps only the element's type and name
 *
 * @param {Object} program The program
 * @param {Object} func The program function
 * @returns {Object} The JSON formated object or null
 */
function __build_function_parameters(program, func) {
	let p = func.parameters, parameters = "";
	for (let i in p) {
		let coma = (i < p.length - 1) ? ', ' : '';
		parameters += `${i}: ${__get_type(program, p[i].type, p[i].language)} ${p[i].name}${coma}`;
	}
	return (parameters);
}

/**
 * Builds the functions that will be inserted in the service object of the thrift file
 *
 * @param {Object} program the functions variable
 * @returns {string} The content of the thrift file
 */
function __build_thrift_service_functions(program) {
	let functions = "";
	for (let func of program.functions) {
		let type = __get_type(program, func.type, func.language);
		let parameters = __build_function_parameters(program, func);
		functions += `	${type} ${func.name} (${parameters}),\n`;
	}
	return (functions);
}

/**
 * Builds the service that will be inserted in the thrift file
 *
 * @param {Object} program the program variable
 * @returns {string} The service content for the thrift file
 */
function __build_thrift_service(program) {
	let service = `service ${program.gitInfo.repo} {\n`;
	service += __build_thrift_service_functions(program);
	service += '}\n';
	return (service);
}

/**
 * Builds the enums that will be inserted in the thrift file
 *
 * @param {String} enums an empty string
 * @param {Object} program the program variable
 * @returns {string} The content of the thrift file
 */
function __build_thrift_enums(enums, program) {
	for (let e of program.enums) {
		enums += `enum ${e.name} {\n`;
		for (let i in e.members) {
			let coma = i < e.members.length - 1 ? ',\n' : '\n';
			let value = e.members[i].value != undefined ? e.members[i].value : i;
			enums += `	${e.members[i].name} = ${value}${coma}`;
		}
		enums += '}\n';
	}
	return (enums);
}


/**
 * Builds the typedefs that will be inserted in the thrift file
 *
 * @param {Sring} td an empty string
 * @param {Object} program the program variable
 * @returns {string} The content of the thrift file
 */
function __build_thrift_typedefs(td, program) {
	for (let t of program.typedefs) td += `typedef ${t.type.replace(/struct:|enum:/g, '')} ${t.name}\n`;
	return (td);
}

/**
 * Builds the thrift file for the given program
 *
 * @param {Object} program the program variable
 * @returns {string} The content of the thrift file
 */
function buildTriftServiceFile(program, callback) {
	let file = `// Typedefs\n${__build_thrift_typedefs("", program)}`;
	file += `\n// Enums\n${__build_thrift_enums("", program)}`;
	file += `\n// Services\n${__build_thrift_service(program)}`;
	let fname = `${__SERVICE_PATH}/${program.gitInfo.repo}.thrift`
	Fs.writeFile(fname, file, function(err) {
		if (err) return callback(err);
		callback(null, fname);
	});
}

/**
 * Builds the GRPC file for the given program
 *
 * @param {Object} program the program variable
 * @returns {string} The content of the thrift file
 */
function buildGRPCServiceFile(program, callback) {
	let file = `${__build_thrift_service(program)}`; //TODO: The same with GRPC
	let fname = `${__SERVICE_PATH}/${program.gitInfo.repo}.thrift`
	Fs.writeFile(fname, file, function(err) {
		if (err) return callback(err);
		callback(null, fname);
	});
}

/**
 * Redirects to the correct RPC framework builder function
 *
 * @param {string} framework the RPC framework (thrift or grpc)
 * @param {Object} program the program variable
 * @param {Function} callback The callback function with (err, thriftFile)
 * @returns {string} The content of the thrift file
 */
function buildRpcService(framework, program, callback) {
	__CONSOLE_DEBUG(`Building the RPC file for ${framework}...`);
	if (framework == __THRIFT) {
		buildTriftServiceFile(program, (err, serviceFilePath) => {
			if (err) return (callback(err));
			return (callback(null, serviceFilePath));
		})
	}
	else if (framework == __GRPC) {
		buildGRPCServiceFile(program, (err, serviceFilePath) => {
			if (err) return (callback(err));
			return (callback(null, serviceFilePath));
		})
	}
	else return (callback('Please provide a valid RPC framework name (thrift or grpc)'));
}

exports.buildRpcService = buildRpcService;