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
const Sharp				= require('sharp');
const MongoCommons		= Rfr('app_commons/qr_mongo_cm');
const ApiResult			= Rfr('app_commons/qr_api_cm').apiResult;
const PromiseResult		= Rfr('app_commons/qr_promises_cm').promiseResult;
const Multer			= require('multer');

/*******************************************************************************
*************************** Checking functions *********************************
*******************************************************************************/

function imageIsValid(imageData) {
	let acceptedExtensions = ['jpg','jpeg','png'];
	let imageExtension = imageData.originalname.split('.').pop();
	return (acceptedExtensions.indexOf(imageExtension) < 0) ? false : true;
}

function videoIsValid(videoData) {
	let acceptedExtensions = ['mp4','mov','avi'];
	let videoExtension = videoData.originalname.split('.').pop();
	return (acceptedExtensions.indexOf(videoExtension) < 0) ? false : true;
}

function dataTypeIsValid(dataType) {
	let acceptedFileTypes = ['image','video'];
	if (!dataType) return (false);
	return (acceptedFileTypes.indexOf(dataType) < 0) ? false : true;
}

/*******************************************************************************
************************ General upload functions ******************************
*******************************************************************************/

function createDirectory(dirPath) {
	return (new Promise((resolve, reject) => {
		Fs.mkdir(dirPath, { recursive: true }, (err) => {
			if (err) return (reject(PromiseResult(false, {}, { message : 'Could not create the directory', error : err })));
			else return (resolve(PromiseResult(true, {})));
		})
	}))
}

function directoryExists(dirPath) {
	return (new Promise((resolve, reject) => {
		Fs.access(path, Fs.constants.W_OK, (err) => {
			if (err) {
				console.log('ERROR ---- 7', err);
				return (reject(PromiseResult(false, {}, err)));
			}
			else return (resolve(PromiseResult(true, 'Directory exists')));
		})
	}))
}

function buildPath(dirPath) {
	return (new Promise((resolve, reject) => {
		console.log('Dir : ',dirPath);
		let asyncFunc = async function() {
			let folders = dirPath.split('/');
			let path = "";
			for (let i = 0; i < folders.length; i++) {
				if (!(folders[i].length)) continue;
				path += '/' + folders[i];
				let dir = await directoryExists(path)
				.catch((err) => {
					let dirAsyncFunc = async function() {
						let created = await createDirectory(path)
						.catch((err) => { return (reject(PromiseResult(false, {}, err.error))); })
					}
					dirAsyncFunc();
				})
			}
			return (resolve(PromiseResult(true, 'Directory exists')));
		}
		asyncFunc();
	}));
}

function unlinkFile(tmpFilePath) {
	return (new Promise((resolve, reject) => {
		Fs.unlink(tmpFilePath, (err) => {
			if (err) return (reject(PromiseResult(false, {}, err)));
			else return (resolve(PromiseResult(true, 'File was successfully unlinked.')));
		})
	}))
}

function writeFile(data, uploadPath) {
	return (new Promise((resolve, reject) => {
		Fs.writeFile(uploadPath, data, (err) => {
			if (err) return (reject(PromiseResult(false, {}, err)));
			else return (resolve(PromiseResult(true, 'File was successfully written.')));
		})
	}));
}

function uploadFile(data, fileName, uploadPath) {
	return (new Promise((resolve, reject) => {
		if (!data) return (reject(PromiseResult(false, {}, "No data was provided")));
		if (!uploadPath) return (reject(PromiseResult(false, {}, "No upload path was provided")));
		buildPath(uploadPath)
		.then(() => {
			writeFile(data, uploadPath + '/' + fileName)
			.then(() => { console.log('File written'); return (resolve(PromiseResult(true, 'File was successfully uploaded.'))); })
			.catch((err) => { console.log("ERROR ------ 8", err); return (reject(PromiseResult(false, {}, err.error))); })
		}).catch((err) => { console.log("ERROR ------ 9", err); return (reject(PromiseResult(false, {}, err.error))); })
	}))
}

/*******************************************************************************
**************************** Backend functions *********************************
*******************************************************************************/

function uploadImage(imageData, formData) {
	return (new Promise((resolve, reject) => {
		if (!imageData || !imageIsValid(imageData)) return (reject(PromiseResult(false, {}, 'Please provide an image')));
		if (!formData || (formData && !(formData.parentElement))) return (reject(PromiseResult(false, {}, 'Please provide a parent element for the image.')));
		Sharp(imageData.path)
		.png().toBuffer().then((data) => {
			let newImageName = Math.random().toString(36).substr(2, 9) + '.png';
			let returnPath = '/uploads/images/' + formData.parentElement;
			let uploadPath = Path.dirname(require.main.filename) + '/public' + returnPath;
			uploadFile(data, newImageName, uploadPath)
			.then((response) => {
				unlinkFile(imageData.path)
				.then((response) => { return (resolve(PromiseResult(true, returnPath + '/' + newImageName)))})
				.catch((err) => { console.log('ERROR ---- 1', err); return (reject(PromiseResult(false, {}, err.error))); })
			}).catch((err) => { console.log('ERROR ---- 2', err); return (reject(PromiseResult(false, {}, err.error))); })
		}).catch((err) => { console.log('ERROR ---- 3', err); return (reject(PromiseResult(false, {}, err))); })
	}))
}

function uploadVideo(req, videoData, formData) {
	return (new Promise((resolve, reject) => {
		if (!videoData || !videoIsValid(videoData)) return (reject(PromiseResult(false, {}, 'Please provide a video')));
		if (!formData || (formData && !(formData.parentElement))) return (reject(PromiseResult(false, {}, 'Please provide a parent element for the video.')));
		let videoExtension = videoData.originalname.split('.').pop();
		let newVideoName = Math.random().toString(36).substr(2, 9) + '.' + videoExtension;
		let returnPath = '/uploads/video/' + formData.parentElement;
		let uploadPath = Path.dirname(require.main.filename) + '/public' + returnPath;
		buildPath(uploadPath)
		.then(() => {
			Fs.rename(videoData.path, uploadPath + '/' + newVideoName, (err) => {
				if (err) { console.log('ERROR ---- 4', err); return (reject(PromiseResult(false, {}, err))); }
				return (resolve(PromiseResult(true, returnPath + '/' + newVideoName)));
			});
		})}).catch((err) => { console.log('ERROR ---- 3', err); return (reject(PromiseResult(false, {}, err.error)));
	}))
}

/*******************************************************************************
****************************** API functions ***********************************
*******************************************************************************/

function apiUploadFile(req, res) {
	if (!(dataTypeIsValid(req.body.dataType)))
		return(res.send(ApiResult(false, {}, 'Please provide a dataType (image, video)')));
	if (req.body.dataType == 'image') {
		console.log("Image");
		uploadImage(req.file, req.body)
		.then((response) => { return(res.send(ApiResult(true, response.result))); })
		.catch((err) => { console.log('ERROR ---- 5', err); return(res.send(ApiResult(false, {}, err.error))); })
	} else if (req.body.dataType == 'video') {
		uploadVideo(req, req.file, req.body)
		.then((response) => { return(res.send(ApiResult(true, response.result))); })
		.catch((err) => { console.log('ERROR ---- 6', err); return(res.send(ApiResult(false, {}, err.error))); })
	}
}

/*******************************************************************************
********************************* Exports **************************************
*******************************************************************************/

// Backend functions export
exports.uploadImage = uploadImage;
exports.uploadVideo = uploadVideo;

// API functions export
exports.apiUploadFile = apiUploadFile;
