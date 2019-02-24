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


Filename : qr_globals_cm.js
By: fsabatie <fsabatie@student.42.fr>
Created: 2018/12/19 20:33:06 by fsabatie
Updated: 2019/02/24 15:20:59 by fsabatie
*/

const Rfr			= require ('rfr');
const Views			= Rfr('app_commons/qr_views_globals_cm.js');

/*******************************************************************************
************************** Environment variables *******************************
*******************************************************************************/

global.__PREFIX				= 'qr_';
global.__BASEDIR			= __dirname;
global.__ROOT_URL			= 'http://localhost:8080';
global.__INPROD				= false;

(__INPROD) ? Rfr('app_commons/qr_prod_credentials_cm.js') : Rfr('app_commons/qr_dev_credentials_cm.js');

// MongoDB info globals
global.__MONGO_URL_OPTIONS			= "?authSource=admin"; // Use the 'admin' database as authentication source
global.__MONGO_DBNAME				= 'quasr'; // Database name
global.__MONGO_URL_CONNECT			= `mongodb://${__MONGO_USER}:${__MONGO_PWD}@${__MONGO_URL}:${__MONGO_PORT}/${__MONGO_URL_OPTIONS}`; // Mongo URL

// Git download info
global.__GIT_DOWNLOAD_FOLDER_PATH = 'GitCode';
global.__GIT_C_FOLDER = 'C';
global.__GIT_PYTHON_FOLDER = 'PYTHON';
global.__GIT_JS_FOLDER = 'JS';
global.__GITHUB = 'github';

// Languages' names
global.__LANGUAGE_C = 'C';

// RPC services
global.__THRIFT = 'thrift';
global.__GRPC = 'grpc';
global.__SERVICE_PATH = 'services';

// Controllers constants (avoiding double inclusion)
global.__CONTROLLERS_JS = false;
global.__PARSER_CONTROLLERS_JS = false;
global.__BUILDER_CONTROLLERS_JS = false;

// Defining environment variables
global.__WARNING = 'warning';
global.__NONBLOCKING = 'blocking';
global.__FATAL = 'fatal';

/*******************************************************************************
************************** Environment functions *******************************
*******************************************************************************/

// Error function
global.__CONSOLE_DEBUG = function(arguments) {
	if (!__INPROD) console.log(arguments);
}

// Error function
global.__ERR = function(string, level = __WARNING) {
	if (level == __WARNING) console.warn(string);
	else if (level == __NONBLOCKING) console.error(string);
	else if (level == __FATAL) throw Error(string);
	return (false);
}

// Result object
global.__RESULT = function(success, result = {}) { return ({success: success, result: result}); }


/*******************************************************************************
************************ Program start & useless fun ***************************
*******************************************************************************/

const QUASR = "\033[2J\033[1;1H________       ___  ___      ________      ________       ________\r\n|\\   __  \\     |\\  \\|\\  \\    |\\   __  \\    |\\   ____\\     |\\   __  \\\r\n\\ \\  \\|\\  \\    \\ \\  \\\\\\  \\   \\ \\  \\|\\  \\   \\ \\  \\___|_    \\ \\  \\|\\  \\\r\n \\ \\  \\\\\\  \\    \\ \\  \\\\\\  \\   \\ \\   __  \\   \\ \\_____  \\    \\ \\   _  _\\\r\n  \\ \\  \\\\\\  \\    \\ \\  \\\\\\  \\   \\ \\  \\ \\  \\   \\|____|\\  \\    \\ \\  \\\\  \\|\r\n   \\ \\_____  \\    \\ \\_______\\   \\ \\__\\ \\__\\    ____\\_\\  \\    \\ \\__\\\\ _\\\r\n    \\|___| \\__\\    \\|_______|    \\|__|\\|__|   |\\_________\\    \\|__|\\|__|\r\n          \\|__|                               \\|_________|\r\n\r\n\r\n\r\n                               ````````````\r\n                           ```````````...::\/::..`\r\n                            ``             ``...:\/:..`\r\n                       `       `.`.`.-..-.````    ```.-.`\r\n                        `.---......`..``..``..--..`   `.::.`\r\n                    ``..```````````......````````.--.....`..`\r\n                `-:-..`    `.:\/++\/++oooossso+:.`````--:-.``..`     `\r\n              `.-:```  ``-\/\/\/::--::\/ossshyyhhhs+\/..```.-..` `.`    .`\r\n          ```..-.`  ``:+o:-..-\/ooo\/\/\/\/\/\/\/\/:\/+yysyo-.`  `..-.` `    `\r\n         `.``..`   `-+o:-.`:o+++::::::++oo\/-\/ssos+-:-.  `\/\/. `..   -.\r\n        `` `+.`   `-+y:-``:++-::--:+\/:\/\/\/omd+:\/--.-oo-` `:+.  -.   --`\r\n          `.-    .::+o...:+s\/-+..+:.`-\/sydy:-+.`\/.+oh\/```os. `\/.  `\/.\r\n         `-:`   `\/\/\/o+.`.\/++\/\/\/`:o. \/mNNmo` -o.-\/.-so:``:o:````  `:-`\r\n         .\/:    .---::. `:ys\/::-.\/ssmh+:..:\/o::\/::o+-..\/s--..`  .-`\r\n         `-.`  `...`.\/o-`.-\/+yso\/--+ysssooo+::+\/+oo-.-ss\/.-` `.-:`\r\n          .-`   ..` `.\/+.``.-+shso+::::::\/\/\/+ossss+:\/\/+-````:+\/.\r\n           `.    `.`  .\/+\/....-\/ooyyyysossssysss+:--.```.\/\/\/\/-`\r\n            ``    `-\/  `-o:....`..-::\/\/\/\/\/:\/:-..`````.:oso:.\r\n                    ..`  .\/o\/-.``...---..----:-::++\/+::.`\r\n                    `-:.```.:\/\/+:--.----::\/+oo\/:--.````\r\n             `.`      `.---.`````.-::::--..`` `````        ..`\r\n               `         `..--.``     ```````     ``````.```\r\n                            ``--.....``..```...--.``\r\n                                    `......`````\r\n\r\n";

console.log(QUASR);
