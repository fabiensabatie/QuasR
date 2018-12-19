/**
 * @Date:   2018-08-05T20:10:40+02:00
 * @Last modified time: 2018-08-05T20:11:21+02:00
 */

if (!__PARSER_CONTROLLERS_JS) {
	const Rfr					= require('rfr');
	/** Pages controllers */
	exports.Parsers				= {};
	exports.Parsers.C			= Rfr('controllers/parsers/C/c_parser.js');
	__PARSER_CONTROLLERS_JS		= true;
}
