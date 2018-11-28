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
const Path				= require('path');
const Multer			= require('multer');
const MongoCommons		= Rfr('app_commons/qr_mongo_cm');
const ApiResult			= Rfr('app_commons/qr_api_cm').apiResult;
const PromiseResult		= Rfr('app_commons/qr_promises_cm').promiseResult;
const States			= Rfr('controllers/api/qr_states_api.js');

class API {
	constructor(answerData) {
		this.hostname = answerData.hostname;
		this.plugins = answerData.plugins;
		this.configuration = answerData.configuration;
		this.tagline = answerData.tagline;
		this.version = answerData.version;
	}
}

/*******************************************************************************
**************************** Backend functions *********************************
*******************************************************************************/

function apiDataIsValid(apiData) {
	return (new Promise((resolve, reject) => {
		if (!(apiData.hostname)) return (reject(PromiseResult(false, null, 'Please provide a hostname')));
		if (!(apiData.configuration)) return (reject(PromiseResult(false, null, 'Please provide a configuration file')));
		if (!(apiData.serviceId)) return (reject(PromiseResult(false, null, 'Please provide a service id')));
		if (!(apiData.tagline)) return (reject(PromiseResult(false, null, 'Please provide a tagline')));
		if (!(apiData.version)) return (reject(PromiseResult(false, null, 'Please provide a version')));
		return (resolve(PromiseResult(true)));
	}))
}

function addAPI(apiData) {
	return (new Promise((resolve, reject) => {
		if (!(apiData.endpoints)) apiData.endpoints = {};
		apiDataIsValid(apiData)
		.then(() => {
			MongoCommons.addElements(__MONGO_APICOLLECTION, apiData)
			.then((addedApi) => {
				MongoCommons.setElements(true, __MONGO_SERVICECOLLECTION, {_id : apiData.serviceId}, {apiId : apiData._id})
				.then(() => {
					States.addState({elementId : apiData._id, elementType: 'api'})
					.then((state) => {
						let stateId = state.result._id;
						return (resolve(PromiseResult(true, Object.assign(apiData, {stateId : stateId}))));
					}).catch((err) => { return (reject(PromiseResult(false, {}, err.error)));})
				}).catch((err) => { return (reject(PromiseResult(false, {}, 'serviceId: ' + apiData.serviceId + ' invalid'))); })
			}).catch((err) => { return (reject(PromiseResult(false, {}, err.error))); })
		}).catch((err) => { return (reject(PromiseResult(false, {}, err.error))); })
	}));
}

/*******************************************************************************
****************************** API functions ***********************************
*******************************************************************************/

function apiAddAPI(req, res) {
	addAPI(req.body)
	.then((addedApi) => { return (res.send(ApiResult(true, addedApi.result))); })
	.catch((err) => { return (res.send(ApiResult(false, err.error))); })
}

/*******************************************************************************
********************************* Exports **************************************
*******************************************************************************/

// Backend functions export

exports.addAPI = addAPI;

// API functions export

exports.apiAddAPI = apiAddAPI;
