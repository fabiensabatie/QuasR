/**
 * @Author: Fabien Sabatié <fabiensabatie>
 * @Date:   2018-07-07T19:56:16+02:00
 * @Email:  fsabatie@student.42.fr
 * @Project: TeachKit
 * @Last modified by:   fabiensabatie
 * @Last modified time: 2018-07-09T16:12:45+02:00
 */

/**
Returns the promise result. Success must be a boolean, result any object,
and and error can be passed as any object. If no error is given, the error
field of the promise result is set to "none".
**/
function apiResult(success, result = {}, error = null) {
	let ret = {
		success : success,
		result : result
	}
	if (error)
		ret.error = error;
	return (ret);
}

function requestIsAllowed(req, res) {
	return (true);
}

exports.apiResult = apiResult;
exports.requestIsAllowed = requestIsAllowed;
