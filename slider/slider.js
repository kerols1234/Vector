var div = document.querySelectorAll('div'),
	span = document.querySelectorAll('span'),
	img = document.querySelectorAll('img');

span[0].onclick = function () {
	'use strict';
	img[0].style.display = 'block';
	img[1].style.display = 'none';
	img[2].style.display = 'none';
};

span[1].onclick = function () {
	'use strict';
	img[1].style.display = 'block';
	img[0].style.display = 'none';
	img[2].style.display = 'none';
};

span[2].onclick = function () {
	'use strict';
	img[2].style.display = 'block';
	img[0].style.display = 'none';
	img[1].style.display = 'none';
};

div[1].onclick = function () {
	'use strict';
	if (img[0].style.display === 'block') {
		img[2].style.display = 'block';
		img[1].style.display = 'none';
		img[0].style.display = 'none';
	} else if (img[1].style.display === 'block') {
		img[0].style.display = 'block';
		img[1].style.display = 'none';
		img[2].style.display = 'none';
	} else if (img[2].style.display === 'block') {
		img[1].style.display = 'block';
		img[2].style.display = 'none';
		img[0].style.display = 'none';
	}
};

div[2].onclick = function () {
	'use strict';
	if (img[0].style.display === 'block') {
		img[1].style.display = 'block';
		img[2].style.display = 'none';
		img[0].style.display = 'none';
	} else if (img[1].style.display === 'block') {
		img[2].style.display = 'block';
		img[1].style.display = 'none';
		img[0].style.display = 'none';
	} else if (img[2].style.display === 'block') {
		img[0].style.display = 'block';
		img[2].style.display = 'none';
		img[1].style.display = 'none';
	}
};
setInterval(function () {
	'use strict';
	if (img[0].style.display === 'block') {
		img[1].style.display = 'block';
		img[2].style.display = 'none';
		img[0].style.display = 'none';
	} else if (img[1].style.display === 'block') {
		img[2].style.display = 'block';
		img[1].style.display = 'none';
		img[0].style.display = 'none';
	} else if (img[2].style.display === 'block') {
		img[0].style.display = 'block';
		img[2].style.display = 'none';
		img[1].style.display = 'none';
	}
}, 2000);
