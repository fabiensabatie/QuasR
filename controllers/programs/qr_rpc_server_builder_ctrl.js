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


Filename : qr_rpc_server_builder_ctrl.js
By: fsabatie <fsabatie@student.42.fr>
Created: 2018/12/27 00:12:03 by fsabatie
Updated: 2019/03/19 21:27:44 by fsabatie
*/

const Fs = require('fs');
const Mustache = require('mustache');

/**
 * Edits the thrift server wrapper files
 *
 * @param {string} framework the RPC framework (thrift or grpc)
 * @param {Object} program the program variable
 * @param {Function} callback The callback function with (err, thriftFile)
 * @returns {string} The content of the thrift file
 */
function editTriftServerWrapperFiles(program, callback) {
	
}


/**
 * Redirects to the correct RPC server wrapper builder function
 *
 * @param {string} framework the RPC framework (thrift or grpc)
 * @param {Object} program the program variable
 * @param {Function} callback The callback function with (err, thriftFile)
 * @returns {string} The content of the thrift file
 */
function buildRpcServerWrapper(framework, program, callback) {
	__CONSOLE_DEBUG(`Building the server wrapper for ${framework}...`);
	if (framework == __THRIFT) {
		editTriftServerWrapperFiles(program, (err, serviceFilePath) => {
			if (err) return (callback(err));
			return (callback(null, serviceFilePath));
		})
	}
	// else if (framework == __GRPC) {
	// 	editGRPCServerWrapperFiles(program, (err, serviceFilePath) => {
	// 		if (err) return (callback(err));
	// 		return (callback(null, serviceFilePath));
	// 	})
	// }
	else return (callback('Please provide a valid RPC framework name (thrift or grpc)'));
}

exports.buildRpcServerWrapper = buildRpcServerWrapper;
