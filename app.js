/**
QuasR.io
Fabien Sabatié
fabien.sabatie@live.fr
*/
"use strict";
const Express				= require('express');
const App					= Express();
const Cookies				= require('cookie-parser');
const BodyParser			= require('body-parser');
const Server				= require('http').createServer(App);
const CompileSaas			= require('express-compile-sass');
const ExpressEjsLayouts		= require('express-ejs-layouts');
const Events				= require('events');
const EventEmitter			= new Events.EventEmitter();
const Rfr					= require('rfr');
const Globals				= Rfr('app_commons/qr_globals_cm');

App.use(Cookies("37iDxGKbZd+12Mt3YrMfPkPohwYh9idxiq44A"));
App.use(CompileSaas({root : process.cwd() + '/public', sourceMap : true
, sourceComments : true, logToConsole : false}));
App.use('/', Express.static(__dirname + '/public'));


App.use(function(req, res, next) {
	res.header("Access-Control-Allow-Origin", "*");
	res.header("Access-Control-Allow-Headers", "Origin, X-Requested-With, Content-Type, Accept");
	next();
});

App.set('view engine', 'ejs');
App.set('view engine', 'pug');

exports.App             = App;
exports.Server          = Server;
exports.EventEmitter    = EventEmitter;
