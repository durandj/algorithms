'use strict';

function swap(elements, index0, index1) {
	const tmp = elements[index0];
	elements[index0] = elements[index1];
	elements[index1] = tmp;
}

function insertionSort(elements) {
	for (let i = 1; i < elements.length; i++) {
		for (let j = 0; j < i; j++) {
			if (elements[i] < elements[j]) {
				swap(elements, i, j);
			}
		}
	}
}

