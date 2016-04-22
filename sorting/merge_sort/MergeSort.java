import java.util.ArrayList;
import java.util.List;

class MergeSort {
	public static <T extends Comparable<T>> List<T> sort(List<T> elements) {
		int size = elements.size();

		if (size <= 1) {
			return elements;
		}

		int midpoint = size / 2;

		List<T> left = sort(elements.subList(0, midpoint));
		List<T> right = sort(elements.subList(midpoint, size));

		// TODO(durandj): this could be done with iterators
		int leftIndex = 0;
		int rightIndex = 0;
		List<T> sorted = new ArrayList<T>();

		while (leftIndex < midpoint && rightIndex < size - midpoint) {
			T leftValue = left.get(leftIndex);
			T rightValue = right.get(rightIndex);

			if (leftValue.compareTo(rightValue) < 0) {
				sorted.add(leftValue);
				leftIndex++;
			}
			else {
				sorted.add(rightValue);
				rightIndex++;
			}
		}

		while (leftIndex < midpoint) {
			sorted.add(left.get(leftIndex));
			leftIndex++;
		}

		while (rightIndex < size - midpoint) {
			sorted.add(right.get(rightIndex));
			rightIndex++;
		}

		return sorted;
	}
}

