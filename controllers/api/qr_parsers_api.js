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
const Parsers			= Rfr('controllers/parsers/qr_parsers_ctrl.js');

/*******************************************************************************
**************************** Backend functions *********************************
*******************************************************************************/

function parseFile(fileType, filePath) {
	return (new Promise((resolve, reject) => {
		if (!fileType) return (reject(PromiseResult(false, {}, 'Please provide a fileType')));
		if (fileType == "C") {
			Parsers.C.parse(filePath)
			.then((fileData) => { return (resolve(PromiseResult(true, fileData.result))) })
			.catch((err) => { return (reject(PromiseResult(false, {}, err.error))) })
		}
	}))
}

/*******************************************************************************
****************************** API functions ***********************************
*******************************************************************************/

function apiParseFile(req, res) {
	parseFile(req.body.fileType, req.body.filePath)
	.then((fileData) => { return (res.send(ApiResult(true, fileData.result))); })
	.catch((err) => { return (res.send(ApiResult(false, err.error))); })
}

/*******************************************************************************
********************************* Exports **************************************
*******************************************************************************/

// Backend functions export

exports.apiParseFile = apiParseFile;

// API functions export
