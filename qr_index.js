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


Filename : qr_index.js
By: fsabatie <fsabatie@student.42.fr>
Created: 2018/12/19 21:20:41 by fsabatie
Updated: 2019/02/22 19:00:14 by fsabatie
*/

"use strict";
const QuasR				= require('./app.js');
const BodyParser		= require('body-parser');
const JsonParser		= BodyParser.json();
const Rfr				= require('rfr');
const UrlParser			= BodyParser.urlencoded({extended: true});
const Ctrl				= Rfr('controllers/qr_ctrl.js');
const Multer			= require('multer');
const Upload			= Multer({ dest: 'public/uploads/tmp/' });

/*******************************************************************************
*************************** Views serving routes *******************************
*******************************************************************************/

let gitInfo = {
	service : 'github',
	author : process.argv[2] ? process.argv[2] : 'terry-finkel',
	repo : process.argv[3] ? process.argv[3] : 'ft_malloc'
}

Ctrl.PROGRAM.getProgram(gitInfo, (err, program) => {
	if (err) return (console.log(`ERR : ${err}`));
	console.log('************************************************');
	console.log('******************* FUNCTIONS ******************');
	console.log('************************************************\n\n');
	for (let func of program.functions) console.log(func);
	console.log('************************************************');
	console.log('********************* ENUMS ********************');
	console.log('************************************************\n\n');
	for (let en of program.enums) console.log(en);
	console.log('************************************************');
	console.log('********************* MACROS *******************');
	console.log('************************************************\n\n');
	for (let macro of program.macros) console.log(macro);
	console.log(`Found ${program.macros.length} macros, and ${program.functions.length} functions.`);
})

/*******************************************************************************
******************************** Error Routes **********************************
*******************************************************************************/
QuasR.App.get('/404', function(req, res) { res.render('/') });
QuasR.App.use(function(req, res, next) { res.redirect('/404') });

QuasR.Server.listen(8080);
console.log("🚀  QuasR is up on 8080 🚀 ");
