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
Updated: 2019/02/24 00:11:33 by fsabatie
*/

const THRIFT_TYPES = {
	C : {
		byte : ['int8_t', 'uint8_t', 'int_least8_t', 'uint_least8_t', 'int_fast8_t'],
		i16 : ['int16_t', 'uint16_t', 'int_least16_t', 'uint_least16_t', 'int_fast16_t'],
		i32 : ['int32_t', 'uint32_t', 'int_least32_t', 'uint_least32_t', 'int_fast32_t', 'int', 'long', 'unsigned long'],
		i64 : ['int64_t', 'uint64_t', 'int_least64_t', 'uint_least64_t', 'int_fast64_t'],
		double : ['double', 'float'],
		string : ['char *'],
		binary : [],
		void : ['void']
	}
}

/**
 * Gets the type from the custom typedefs, enums, or structs from the user's code
 *
 * @param {Object} typedefs The program.typedefs variable
 * @param {Object} enums The program.typedefs variable
 * @param {Object} structs The program.typedefs variable
 * @param {string} type The tag type
 * @returns {Object} The corresponding type
 */
function __get_corresponding_custom_type(typedefs, enums, stucts, type) {

}


__get_corresponding_custom_type()

/**
 * Keeps only the element's type and name
 *
 * @param {Object} e The element (a function parameter or enum value)
 * @returns {Object} The JSON formated object
 */
function __get_corresponding_thrift_type(type) {

}

/**
 * Builds the functions that will be inserted in the service object of the thrift file
 *
 * @param {Object} functions the program.functions variable
 * @returns {string} The content of the thrift file
 */
function __build_thrift_service_functions(functions) {
}

/**
 * Builds the service that will be inserted in the thrift file
 *
 * @param {Object} functions the program.functions variable
 * @param {string} serviceName the program.name variable
 * @returns {string} The content of the thrift file
 */
function __build_thrift_service(functions, serviceName) {
	let service = `service ${serviceName} {`;
}

/**
 * Builds the thrift file for the given program
 *
 * @param {Object} program the program variable
 * @param {Function} callback The callback function with (err, thriftFile)
 * @returns {string} The content of the thrift file
 */
function buildTriftServiceFile(program, callback) {
	for (let func of program.funtions)
	return callback('Not implemented yet.')
}

/**
 * Builds the GRPC file for the given program
 *
 * @param {Object} program the program variable
 * @param {Function} callback The callback function with (err, thriftFile)
 * @returns {string} The content of the thrift file
 */
function buildGRPCServiceFile(program, callback) {
	return callback('Not implemented yet.')
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
	if (framework == __THRIFT) buildTriftServiceFile(program, callback);
	else if (framework == __GRPC) buildGRPCServiceFile(program, callback);
	else return (callback('Please provide a valid RPC framework name (thrift or grpc)'));
}

exports.buildRpcService = buildRpcService;
