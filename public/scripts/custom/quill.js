import * as Notifications from '/bazinga/js/components/notifications.js';

// Implement and register module
export class FileUpload {

	/** Instantiate the module given a quill instance and any options */
	constructor(quill, options = {}) {
		// save the quill reference
		this.quill = quill;
		// save options
		this.options = options;
		// listen for drop and paste events
		if (this.options.image)
			this.quill.getModule('toolbar').addHandler('image', this.selectLocalFile.bind({this : this, dataType : 'image'}));
		if (this.options.video)
			this.quill.getModule('toolbar').addHandler('video', this.selectLocalFile.bind({this : this, dataType : 'video'}));
	}


	selectLocalFile() {
		let dataType = this.dataType;
		let input = document.createElement('input');
		let obj = this.this;
		obj.dataType = dataType;
		console.log(dataType);
		input.setAttribute('type', 'file');
		input.click();
		input.onchange = () => {
			let file = input.files[0];
			console.log("/^"+ dataType + "\//");
			let regex = new RegExp('^' + dataType);
			console.log(regex)
			if (regex.test(file.type)) {
				let checkBeforeSend = obj.options.checkBeforeSend || obj.checkBeforeSend.bind(obj);
				checkBeforeSend(file, obj.sendToServer.bind(obj));
			} else {
				if (dataType == 'image') Notifications.sendBazNotif('Please select an image.', false, 4000, 'warning');
				else if (dataType == 'video') Notifications.sendBazNotif('Please select a video.', false, 4000, 'warning');
			}
			input.value = null;
		};
	}

	/** Insert the image into the document at the current cursor position */
	insert(dataUrl) {
		const selection = this.quill.getSelection();
		const index = selection ? selection.index : this.quill.getLength();
		this.quill.insertEmbed(index, this.dataType, dataUrl, 'user');
	}

	/** Send to server */
	sendToServer(file) {
		let callbackOK = this.options.callbackOK || this.uploadImageCallbackOK.bind(this);
		let callbackKO = this.options.callbackKO || this.uploadImageCallbackKO.bind(this);
		let formData = new FormData();
		let keys =  Object.keys(this.options.formData);
		for (let i = 0; i < keys.length; i++) { formData.append(keys[i], this.options.formData[keys[i]]) }
		formData.append('file', file);
		formData.append('dataType', this.dataType);
		console.log(this.dataType);
		axios.post(this.options.url, formData)
		.then((response) => {
			if (response.data.success) { this.insert(response.data.result); }
			else {
				Notifications.sendBazNotif('Error while uploading your image.', false, 4000, 'error');
				console.log('Error : ', response.data.error)
			}
		})
		.catch((err) => {
			Notifications.sendBazNotif('Error while uploading your image.', false, 4000, 'error');
			console.log(err)
		})
	}

	/** Check file before sending to the server */
	checkBeforeSend(file, next) { next(file); }
	/** callback on image upload succesfull */
	uploadImageCallbackOK(response, next) { next(response); }
	/** callback on image upload failure */
	uploadImageCallbackKO(error) { alert(error); }
}

Quill.register('modules/fileUpload', FileUpload);

export function initQuillEditor(selector) {
	let quill = new Quill(selector, {
		modules: {
			toolbar: [
				['bold', 'italic', 'underline', 'strike'],
				[{ 'list': 'ordered'}, { 'list': 'bullet' }],
				[{ 'size': ['small', false, 'large', 'huge'] }],
				[{ 'color': [] }, { 'background': [] }],
				[{ 'font': [] }],
				[{ 'align': [] }],
				['link', 'image', 'video']
			],
			fileUpload: {
				url: "/qkit/api/upload/",
				image: true,
				video: true,
				formData : { parentElement : selector.split('_')[1] }
			}
		},
		theme: 'snow'
	});
}

export function initAllQuills() {
	let questionContents = document.getElementsByClassName("question_content_editor");
	let answerContents = document.getElementsByClassName("answer_content_editor");
	// Starting from one to avoid the models
	for (let i = 1; i < questionContents.length; i++) initQuillEditor('#' + questionContents[i].id);
	for (let i = 1; i < answerContents.length; i++) initQuillEditor('#' + answerContents[i].id);
}

