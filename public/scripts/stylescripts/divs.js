function noCarriageOnEditable() {
	let noCarriageEditableDivs = document.querySelectorAll('[nocarriageeditable]') ;
	for (let i = 0; i < noCarriageEditableDivs.length; i++) {
		let elem = noCarriageEditableDivs[i]
		elem.addEventListener('keypress', function(e) {
			if (e.which === 13) {
				e.preventDefault();
				noCarriageEditableDivs[i].blur();
			}
		});
	}
}

noCarriageOnEditable();
