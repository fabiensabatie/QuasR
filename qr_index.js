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
Updated: 2019/02/24 15:14:09 by fsabatie
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

__INIT_APP();

let gitInfo = {
	service : 'github',
	author : process.argv[2] ? process.argv[2] : 'terry-finkel',
	repo : process.argv[3] ? process.argv[3] : 'ft_malloc'
}

__EVENT_EMITTER.on(__READY_APP,() => {
	console.log(`Building the RPC for ${gitInfo.repo} by ${gitInfo.author}.`);
	Ctrl.PROGRAM.getProgram(gitInfo, (err, service) => {
		if (err) return (console.log(`ERR : ${err}`));
		console.log(`Service file created at ${service} \x1b[32m✓\x1b[0m`);
	})
});

// /*******************************************************************************
// ******************************** Error Routes **********************************
// *******************************************************************************/
// QuasR.App.get('/404', function(req, res) { res.render('/') });
// QuasR.App.use(function(req, res, next) { res.redirect('/404') });

// QuasR.Server.listen(8080);
// console.log("🚀  QuasR is running 🚀 ");
