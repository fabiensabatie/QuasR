/**
 * @Date:   2018-08-05T20:10:40+02:00
 * @Last modified time: 2018-08-05T20:11:21+02:00
 */

if (!__CONTROLLERS_JS) {
	const Rfr					= require('rfr');
	/** Pages controllers */
	exports.PAGES				= {};
	exports.PAGES.Home			= Rfr('controllers/pages/qr_home_ctrl.js');
	/** API controllers */
	exports.API					= {};
	/** Upload Controllers */
	__CONTROLLERS_JS			= true;
}
