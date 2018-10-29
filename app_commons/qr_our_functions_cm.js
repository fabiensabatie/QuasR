/**
| |                | |   | |  (_) |
| |_ ___  __ _  ___| |__ | | ___| |_
| __/ _ \/ _` |/ __| '_ \| |/ / | __|
| ||  __/ (_| | (__| | | |   <| | |_
 \__\___|\__,_|\___|_| |_|_|\_\_|\__|

 * @Author: Fabien Sabatié <fabiensabatie>
 * @Date:   2018-07-16T12:03:31+02:00
 * @Email:  fsabatie@student.42.fr
 * @Filename: tck_prototypes_cm.js
 * @Last modified by:   danielsaadia
 * @Last modified time: 2018-09-24T08:46:13+02:00
**/

let tckArrays = {
	arrayIncludesArr : function(bigArray, littleArray) {
		for (let i = 0; i < littleArray.length; i++) {
			if (bigArray.indexOf(littleArray[i]) < 0) {
				return (false);
			}
		}
		return (true);
	},
	arrayIntersect : function(arr1, arr2) {
		let ret = [];
		for (let i = 0; i < arr1.length; i++) {
			if (arr2.indexOf(arr1[i]) >= 0)
				ret.push(arr1[i]);
		}
		return ret;
	},
	subArray(arr, func) {
		let ret = [];
		for (let i = 0; i < arr.length; i++) {
			if (func(arr[i]))
				ret.push(arr[i]);
		}
		return ret;
	},
	findIndexInObjArrByKey(arr, key, equals) {
		for (let i = 0; i < arr.length; i++) {
			if (arr[i][key] == equals)
				return (arr[i]);
		}
		return false;
	}
};

let jsonObjects = {
	getObjByArrPath : function(jsonObj, arrPath) {
		if (!arrPath || arrPath == [])
			return (jsonObj);
		let ret = jsonObj;
		for (let i = 0; i < arrPath.length; i++)
			ret = ret[arrPath[i]];
		return (ret);
	},
	deepAssign(obj1, obj2) {
		for (let key in obj2) {
			if (!(typeof obj1[key] == 'object' && obj2[key] && typeof obj2[key] == 'object')) {
				obj1[key] = obj2[key];
			}
			else if (obj1[key] != null && obj2[key] != null)
				this.deepAssign(obj1[key], obj2[key]);
		}
		return obj1;
	}
}

String.prototype.killAllSpaces = function() {
	return this.replace(/\s/g,'');
}

String.prototype.replaceAt = function(index, replacement) {
	let ret = this.substr(0, index) + replacement + this.substr(index + replacement.length);
	return ret;
}

daysBetween = function(date) {
	let one_day=1000*60*60*24;
	// Convert both dates to milliseconds
	let now = new Date();
	let then = new Date(date);
	// Calculate the difference in milliseconds
	let difference_ms = now - then;
	// Convert back to days and return
	return Math.round(difference_ms/one_day);
}

function isWellDefined(thing, strict = false) {
	if (thing != 0 && !thing)
		return false;
	if (thing == null)
		return false;
	if (typeof thing == 'array' && thing.length == 0 && strict)
		return false;
	if (typeof thing == 'object' && Object.keys(thing).length == 0 && strict)
		return false;
	try {return thing;}
	catch(e) {return false;}
	return thing;
}

exports.tckArrays = tckArrays;
exports.jsonObjects = jsonObjects;
exports.daysBetween = daysBetween;
exports.isWellDefined = isWellDefined;
