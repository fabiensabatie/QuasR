/**
 * @Date:   2018-08-05T20:10:40+02:00
 * @Last modified time: 2018-08-05T20:11:21+02:00
 */

if (!__CONTROLLERS_JS) {
	const Rfr				= require('rfr');
	/** Pages controllers */
	exports.Dashboard		= Rfr('controllers/pages/qr_dashboard_ctrl.js');
	/** API controllers */
	exports.API = {};
	exports.API.Uploads		= Rfr('controllers/api/qr_uploads_api.js');
	/** Upload Controllers */
	__CONTROLLERS_JS		= true;
}
