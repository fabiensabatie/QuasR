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


Filename : stardust.js
By: fsabatie <fsabatie@student.42.fr>
Created: 2019/01/21 11:36:31 by fsabatie
Updated: 2019/02/07 15:42:30 by fsabatie
*/

let socket = io('http://localhost:8080');

socket.on('message', (data) => {
	starDust.log = data.text;
	console.log('Message:', data.text);
	if (data.finish) starDust.parseButton = "Parse repository";
	if (data.program) starDust.program = data.program.availableFunctions;
});

let starDust = new Vue({
	el: '#stardustDiv',
	data: {
		repo_service: 'github',
		repo_author : 'fabiensabatie',
		repo_name: 'libft',
		repo_author_isEmpty: false,
		repo_name_isEmpty: false,
		log : '',
		parseButton : 'Parse repository',
		program : ''
	},
	methods: {
		parseRepo: function() {
			let data = this._data;
			data.log = '';
			data.program = '';
			data.repo_author_isEmpty = (!data.repo_author.length) ? true : false;
			data.repo_name_isEmpty = (!data.repo_name.length) ? true : false;
			if (data.repo_service.length && data.repo_author.length && data.repo_name.length) {
				data.repo_author_isEmpty = false;
				data.repo_name_isEmpty = false;
				socket.emit('stardustParse', {service: data.repo_service, name:  data.repo_name, author:  data.repo_author });
				data.parseButton = '<img src="/assets/images/stardust/loader.gif"/>';
			}
		}
	}
})
