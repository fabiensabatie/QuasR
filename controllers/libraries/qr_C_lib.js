/**
 * @Author: Fabien Sabatié <fabiensabatie>
 * @Date:   2018-07-07T17:44:38+02:00
 * @Email:  fsabatie@student.42.fr
 * @Project: PeachMe
 * @Last modified by:
 * @Last modified time: 2018-08-05T20:31:53+02:00
 */

const Rfr				= require('rfr');
const Mongo				= require('mongodb');
const Bcrypt			= require('bcrypt');
const MongoCommons		= Rfr('app_commons/qr_mongo_cm');

/*******************************************************************************
**************************** Backend functions *********************************
*******************************************************************************/

function getLines(fileString) {
	let lines = [];
	let i = 0;
	while (i < fileString.length) {
		let nIndex = fileString.indexOf('\n', i);
		(nIndex >= 0) ? lines.push(fileString.slice(i, nIndex)) : lines.push(fileString.slice(i, fileString.length - 1));
		i = (nIndex >= 0) ? nIndex + 1 : fileString.length;
	}
	return (lines);
}


function getAllIndexes(arr, val) {
	let indexes = [], i = -1;
	while ((i = arr.indexOf(val, i + 1)) != -1) { indexes.push(i); }
	return (indexes);
}

function getFunction(lines, index) {
	let i = index;
	while (lines[i] != "*/") i++;
	i++;
	let func = {};
	let type = lines[i].split(' ')[0];
	let name = lines[i].split(' ')[1];
	name = name.slice(0, name.indexOf('('));
	return ({name: name, return: type});
}

function listFunctions(fileString) {
	let lines = getLines(fileString);
	let qIndexes = getAllIndexes(lines, 'QuasR.io');
	let functions = [];
	for (let i = 0; i < qIndexes.length; i++) {
		functions.push(getFunction(lines, qIndexes[i]))
	}
	console.log(functions);
}

function insertIncludes(fileData, includes) {
	for (let i = 0; i < includes.length; i++) fileData = fileData.concat("#include <" + includes[i] + ">\n");
	return (fileData);
}

function buildFunctionForMain(func) {

	let parameters = new String();
	for (var i = 0; i < func.parameters.length; i++) {
		parameters = parameters.concat(`QuasR->${func.parameters[i].name}`);
		if (i < func.parameters.length - 1) parameters = parameters.concat(', ')
	}
	let functionProtype = `QuasrReturnValue("${func.return}", ${func.name}(${parameters}));`;
	return (functionProtype);
}

function insertMain(fileData, functions) {
	fileData = fileData.concat(`int main(void) {\n\tquasr *QuasR;\n\twhile (1) {\n\t\tQuasR = getQuasRInput();\n\t\tif (QuasR->stop) break;\n`);
	for (let i = 0; i < functions.length; i++) {
		let functionCall = buildFunctionForMain(functions[i]);
		fileData = fileData.concat(`\t\tif (strcompare(QuasR->funcName, "${functions[i].name}")) {\n`);
		fileData = fileData.concat(`\t\t\t${functionCall}\n\t\t}\n`);
	}
	fileData = fileData.concat(`\t}\n}\n`);
	return (fileData);
}

function buildMain() {
	let serviceInfo = {
		includes: ["quasr.h"],
		functions: [{
			name: "ft_strlen",
			return: "int",
			parameters: [{
				name: "str",
				type: "char*"
			}]
		},
		{
			name: "ft_strchr",
			return: "int",
			parameters: [{
				name: "str",
				type: "char*"
			},
			{
				name: "c",
				type: "char"
			}]
		},
		{
			name: "ft_strdup",
			return: "char*",
			parameters: [{
				name: "str",
				type: "char*"
			}]
		},
		{
			name: "ft_strrev",
			return: "char*",
			parameters: [{
				name: "str",
				type: "char*"
			}]
		}]
	};
	let fileData = new String();
	fileData = insertIncludes(fileData, serviceInfo.includes);
	fileData = insertMain(fileData, serviceInfo.functions);
	console.log(fileData);
}

exports.listFunctions = listFunctions;
exports.buildMain = buildMain;
