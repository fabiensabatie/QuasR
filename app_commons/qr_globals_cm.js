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


Filename : qr_globals_cm.js
By: fsabatie <fsabatie@student.42.fr>
Created: 2018/12/19 20:33:06 by fsabatie
Updated: 2018/12/20 00:03:10 by fsabatie
*/

const Rfr			= require ('rfr');
const Prototypes	= Rfr('app_commons/qr_prototypes_cm.js');

/*******************************************************************************
************************** Environment variables *******************************
*******************************************************************************/

global.__PREFIX				= 'qr_';
global.__BASEDIR			= __dirname;
global.__ROOT_URL			= 'http://localhost:8080';

// MongoDB info globals
global.__MONGO_URL					= 'mongodb://localhost:27017/';
global.__MONGO_DBNAME				= 'QuasR_db';

// Views info globals
global.__VIEWSPATH = 'dev/';
global.__DASH_PAGE = __PREFIX + 'dashboard';
global.__HOME_PAGE = __PREFIX + 'home';
global.__LOGIN_PAGE = __PREFIX + 'login';

// Controllers constants (avoiding double inclusion)
global.__CONTROLLERS_JS = false;
global.__PARSER_CONTROLLERS_JS = false;

// Defining environment variables
global.__WARNING = 'warning';
global.__NONBLOCKING = 'blocking';
global.__FATAL = 'fatal';

/*******************************************************************************
************************** Environment functions *******************************
*******************************************************************************/

// Error function
global.__ERR = function(string, level = __WARNING) {
	if (level == __WARNING) console.warn(string);
	else if (level == __NONBLOCKING) console.error(string);
	else if (level == __FATAL) throw Error(string);
	return (false);
}

// Result object
global.__RESULT = function(success, result = {}) {
	return ({success: success, result: result});
}
