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
const PromiseResult		= Rfr('app_commons/qr_promises_cm').promiseResult;
const CLib				= Rfr('controllers/libraries/qr_C_lib.js');
/*******************************************************************************
**************************** Backend functions *********************************
*******************************************************************************/

function parse(filePath) {
	return (new Promise((resolve, reject) => {
		if (!filePath) return (reject(PromiseResult(false, {}, 'Please provide a filePath')))
		Fs.readFile(filePath, 'utf8', (err, fileData) => {
			if (err) return (reject(PromiseResult(false, {}, err)));
			CLib.listFunctions(fileData);
			CLib.buildMain();
			return (resolve(PromiseResult(true, fileData)));
		})
	}));
}

/*******************************************************************************
********************************* Exports **************************************
*******************************************************************************/

// Backend functions export
exports.parse = parse;
