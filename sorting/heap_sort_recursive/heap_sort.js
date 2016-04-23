'use strict';

function swap(elements, index0, index1) {
	const tmp = elements[index0];
	elements[index0] = elements[index1];
	elements[index1] = tmp;
}

function parentIndex(index) {
	return Math.floor(index / 2);
}

function leftIndex(index) {
	return index * 2;
}

function rightIndex(index) {
	return index * 2 + 1;
}

function heapify(elements, parent, size) {
	const left = leftIndex(parent);
	const right = rightIndex(parent);
	let largest = parent;

	if (left < size && elements[parent] < elements[left]) {
		largest = left;
	}

	if (right < size && elements[largest] < elements[right]) {
		largest = right;
	}

	if (largest != parent) {
		swap(elements, parent, largest);
		heapify(elements, largest, size);
	}
}

function heapSort(elements) {
	const lastParent = parentIndex(elements.length - 1);
	for (let i = lastParent; i > 0; i--) {
		heapify(elements, i, elements.length);
	}

	for (let i = elements.length - 1; i > 0; i--) {
		swap(elements, 0, i);

		heapify(elements, 0, i);
	}
}

let a = [9, 8, 7, 6, 5, 4, 3, 2, 1, 0];
heapSort(a);

console.log(a);

