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

function stateIsValid(state) {
	return (new Promise((resolve, reject) => {
		if (!(state.elementId)) return (reject(PromiseResult(false, null, 'Please provide an element id')));
		if (!(state.elementType)) return (reject(PromiseResult(false, null, 'Please provide an element type (api, microservice, etc.)')));
		return (resolve(PromiseResult(true)));
	}))
}

function addState(state) {
	return (new Promise((resolve, reject) => {
		stateIsValid(state)
		.then(() => {
			MongoCommons.addElements(__MONGO_APISTATESCOLLECTION, state)
			.then((addedState) => {
				let collection = (state.elementType == 'api') ? __MONGO_APICOLLECTION : __MONGO_SERVICECOLLECTION;
				MongoCommons.setElements(true, collection, {_id : state.elementId}, {stateId : state._id})
				.then(() => { return (resolve(PromiseResult(true, state))) })
				.catch((err) => { return (reject(PromiseResult(false, {}, err.error))); })})
			.catch((err) => { return (reject(PromiseResult(false, {}, err.error))); }) })
		.catch((err) => { return (reject(PromiseResult(false, {}, err.error))); })
	}))
}

/*******************************************************************************
****************************** API functions ***********************************
*******************************************************************************/

function apiAddState(req, res) {
	addState(req.body)
	.then((addedState) => { return (res.send(ApiResult(true, addedState.result))); })
	.catch((err) => { return (res.send(ApiResult(false, err.error))); })
}

/*******************************************************************************
********************************* Exports **************************************
*******************************************************************************/

// Backend functions export

exports.addState = addState;

// API functions export

exports.apiAddState = apiAddState;
