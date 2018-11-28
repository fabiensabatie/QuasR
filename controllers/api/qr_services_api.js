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
const States			= Rfr('controllers/api/qr_states_api.js');

/*******************************************************************************
**************************** Backend functions *********************************
*******************************************************************************/

function serviceIsValid(service) {
	return (new Promise((resolve, reject) => {
		if (!(service.type) && !(Array.isArray(service.type))) return (reject(PromiseResult(false, null, 'Please provide a service id')));
		if (!(service.parameters)) return (reject(PromiseResult(false, null, 'Please provide a service id')));
		return (resolve(PromiseResult(true)));
	}))
}

function addService(service) {
	return (new Promise((resolve, reject) => {
		serviceIsValid(service)
		.then(() => {
			MongoCommons.addElements(__MONGO_SERVICECOLLECTION, service)
			.then((addedService) => {
				States.addState({elementId : service._id, elementType: 'service'})
				.then((state) => {
					let stateId = state.result._id;
					return (resolve(PromiseResult(true, Object.assign(service, {stateId : stateId}))));
				}).catch((err) => { return (reject(PromiseResult(false, {}, err.error))); })
			}).catch((err) => { return (reject(PromiseResult(false, {}, err.error))); })
		}).catch((err) => { return (reject(PromiseResult(false, {}, err.error))); })
	}))
}

/*******************************************************************************
****************************** API functions ***********************************
*******************************************************************************/

function apiAddService(req, res) {
	addService(req.body)
	.then((addedService) => { return (res.send(ApiResult(true, addedService.result))); })
	.catch((err) => { return (res.send(ApiResult(false, err.error))); })
}

/*******************************************************************************
********************************* Exports **************************************
*******************************************************************************/

// Backend functions export

exports.addService = addService;

// API functions export

exports.apiAddService = apiAddService;
