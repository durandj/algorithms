public class HeapSort {
    private static int parentIndex(int index) {
        return index / 2;
    }

    private static int leftIndex(int index) {
        return index * 2;
    }

    private static int rightIndex(int index) {
        return index * 2 + 1;
    }

    private static <T> void swap(T[] elements, int index0, int index1) {
        T tmp = elements[index0];
        elements[index0] = elements[index1];
        elements[index1] = tmp;
    }

    private static <T extends Comparable<T>> void heapify(T[] elements, int parent, int size) {
        int left = leftIndex(parent);
        int right = rightIndex(parent);
        int largest = parent;

        if (left < size && elements[parent].compareTo(elements[left]) < 0) {
            largest = left;
        }

        if (right < size && elements[largest].compareTo(elements[right]) < 0) {
            largest = right;
        }

        if (largest != parent) {
            swap(elements, parent, largest);
            heapify(elements, largest, size);
        }
    }

    public static <T extends Comparable<T>> void sort(T[] elements) {
        if (elements == null) {
            return;
        }

        int size = elements.length;

        for (int i = parentIndex(size - 1); i >= 0; i--) {
            heapify(elements, i, size);
        }

        for (int i = size - 1; i > 0; i--) {
            swap(elements, 0, i);
            heapify(elements, 0, i);
        }
    }

    public static void main(String[] args) {
        Integer[] elements = new Integer[] {10, 9, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 0};

        sort(elements);

        for (Integer v : elements) {
            System.out.println(v);
        }
    }
}
