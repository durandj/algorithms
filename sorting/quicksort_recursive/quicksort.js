'use strict';

function swap(elements, index0, index1) {
	const tmp = elements[index0];
	elements[index0] = elements[index1];
	elements[index1] = tmp;
}

function partition(elements, start, end) {
	const value = elements[end];
	let i = start - 1;

	for (let p = start; p < end; p++) {
		if (elements[p] < value) {
			i++;
			swap(elements, p, i);
		}
	}

	i++;
	swap(elements, i, end);

	return i;
}

function quicksort(elements, start, end) {
	if (start === undefined) {
		start = 0;
	}

	if (end === undefined) {
		end = elements.length - 1;
	}

	if (start >= end) {
		return;
	}

	const p = partition(elements, start, end);

	quicksort(elements, start, p - 1);
	quicksort(elements, p + 1, end);
}

