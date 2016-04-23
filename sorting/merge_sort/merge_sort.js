'use strict';

function swap(elements, index0, index1) {
	const tmp = elements[index0];
	elements[index0] = elements[index1];
	elements[index1] = tmp;
}

function mergeSort(elements) {
	const size = elements.length;

	if (size <= 1) {
		return elements;
	}

	const midpoint = Math.floor(size / 2);
	const left = mergeSort(elements.slice(0, midpoint));
	const right = mergeSort(elements.slice(midpoint, size));
	let sorted = [];

	while (left.length > 0 && right.length > 0) {
		if (left[0] <= right[0]) {
			sorted.push(left.shift());
		}
		else {
			sorted.push(right.shift());
		}
	}

	return sorted.concat(left).concat(right);
}

