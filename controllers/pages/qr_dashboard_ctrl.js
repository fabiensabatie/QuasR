/**
 * @Author: Fabien Sabatié <fabiensabatie>
 * @Date:   2018-07-07T17:44:38+02:00
 * @Email:  fsabatie@student.42.fr
 * @Project: PeachMe
 * @Last modified by:
 * @Last modified time: 2018-08-05T20:31:53+02:00
 */

const Rfr				= require('rfr');
const Mongo				= require('mongodb');
const Bcrypt			= require('bcrypt');
const MongoCommons		= Rfr('app_commons/qr_mongo_cm');

/**
Home page page GET method.
**/
function gDashboard(req, res) {
	let locals = { title: "Dashboard" };
	return (res.render(__VIEWSPATH + __DASH_PAGE, locals));
}

exports.gDashboard = gDashboard;
