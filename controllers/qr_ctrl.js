/**
 * @Date:   2018-08-05T20:10:40+02:00
 * @Last modified time: 2018-08-05T20:11:21+02:00
 */

if (!__CONTROLLERS_JS) {
	const Rfr					= require('rfr');
	/** Pages controllers */
	exports.PAGES				= {};
	exports.PAGES.Dashboard		= Rfr('controllers/pages/qr_dashboard_ctrl.js');
	exports.PAGES.Home			= Rfr('controllers/pages/qr_home_ctrl.js');
	/** API controllers */
	exports.API					= {};
	exports.API.APIs			= Rfr('controllers/api/qr_apis_api.js');
	exports.API.Services		= Rfr('controllers/api/qr_services_api.js');
	exports.API.States			= Rfr('controllers/api/qr_states_api.js');
	exports.API.Endpoints		= Rfr('controllers/api/qr_endpoints_api.js');
	exports.API.Parsers			= Rfr('controllers/api/qr_parsers_api.js');
	exports.API.Uploads			= Rfr('controllers/api/qr_uploads_api.js');
	/** Upload Controllers */
	__CONTROLLERS_JS			= true;
}
