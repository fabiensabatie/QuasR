/**
* @Author: Fabien Sabatié <fabiensabatie>
* @Date:   2018-07-07T17:44:38+02:00
* @Email:  fsabatie@student.42.fr
* @Project: QKIT
* @Last modified by:
* @Last modified time: 2018-08-05T20:31:53+02:00
*/

const Rfr				= require('rfr');
const Fs				= require('fs');
const Mongo				= require('mongodb');
const Multer			= require('multer');
const Path				= require('path');
const MongoCommons		= Rfr('app_commons/qr_mongo_cm');
const ApiResult			= Rfr('app_commons/qr_api_cm').apiResult;
const PromiseResult		= Rfr('app_commons/qr_promises_cm').promiseResult;

/*******************************************************************************
**************************** Backend functions *********************************
*******************************************************************************/

function endpointsAreValid(endpoints) {
	return (new Promise((resolve, reject) => {
		if (!(endpoints) || !(Array.isArray(endpoints))) return (reject(PromiseResult(false, null, 'Please provide an array of endpoints')));
		for (i in endpoints) {
			if (!(endpoints[i].apiId)) return (reject(PromiseResult(false, null, {message: 'Please provide an API id', endpoint : endpoints[i]})));
			if (endpoints[i].apiId != endpoints[0].apiId) return (reject(PromiseResult(false, null, 'All endpoints must belong to the same API')));
			if (!(endpoints[i].configuration)) return (reject(PromiseResult(false, null, {message: 'Please provide a configuration', endpoint : endpoints[i]})));
			if (!(endpoints[i].route)) return (reject(PromiseResult(false, null, {message: 'Please provide a route', endpoint : endpoints[i]})));
		}
		return (resolve(PromiseResult(true)));
	}))
}

function formatEndpoints(endpoints) {
	let format = {};
	for (i in endpoints) format['endpoints.' + endpoints[i].route] = endpoints[i]._id;
	return (format);
}

function addEndpoints(endpoints) {
	return (new Promise((resolve, reject) => {
		endpointsAreValid(endpoints)
		.then(() => {
			MongoCommons.addElements(__MONGO_ENDPOINTCOLLECTION, endpoints)
			.then((addedEndpoints) => {
				MongoCommons.setElements(true, __MONGO_APICOLLECTION, {_id: endpoints[0].apiId}, formatEndpoints(endpoints))
				.then(() => { return (resolve(PromiseResult(true, endpoints))); }) })
				.catch((err) => { return (reject(PromiseResult(false, {}, err.error))); })
			.catch((err) => { return (reject(PromiseResult(false, {}, err.error))); })
		}).catch((err) => { return (reject(PromiseResult(false, {}, err.error))); })
	}))
}

/*******************************************************************************
****************************** API functions ***********************************
*******************************************************************************/

function apiAddEndpoints(req, res) {
	addEndpoints(req.body.endpoints)
	.then((addedEndpoints) => { return (res.send(ApiResult(true, addedEndpoints.result))); })
	.catch((err) => { return (res.send(ApiResult(false, err.error))); })
}

/*******************************************************************************
********************************* Exports **************************************
*******************************************************************************/

// Backend functions export

exports.addEndpoints = addEndpoints;

// API functions export

exports.apiAddEndpoints = apiAddEndpoints;
