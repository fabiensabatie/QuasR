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


/*******************************************************************************
**************************** Backend functions *********************************
*******************************************************************************/



/*******************************************************************************
****************************** API functions ***********************************
*******************************************************************************/


/*******************************************************************************
********************************* Exports **************************************
*******************************************************************************/

// Backend functions export


// API functions export
