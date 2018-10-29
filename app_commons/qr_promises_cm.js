/**
 * @Author: Fabien Sabatié <fabiensabatie>
 * @Date:   2018-07-07T19:56:16+02:00
 * @Email:  fsabatie@student.42.fr
 * @Project: PeachMe
 * @Last modified by:   fabiensabatie
 * @Last modified time: 2018-07-07T22:22:33+02:00
 */

/**
Returns the promise result. Success must be a boolean, result any object,
and and error can be passed as any object. If no error is given, the error
field of the promise result is set to "none".
**/
function promiseResult(success, result = {}, error = false) {
	let ret = {
		success : success,
		error : error,
		result : result
	}
	return (ret);
}

exports.promiseResult = promiseResult;
