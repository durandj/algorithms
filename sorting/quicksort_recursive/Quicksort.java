public class Quicksort {
    private static <T> void swap(T[] elements, int index0, int index1) {
        T tmp = elements[index0];
        elements[index0] = elements[index1];
        elements[index1] = tmp;
    }

    private static <T extends Comparable<T>> int partition(T[] elements, int start, int end) {
        T value = elements[end];
        int i = start - 1;

        for (int p = start; p < end; p++) {
            if (elements[p].compareTo(value) <= 0) {
                i++;
                swap(elements, p, i);
            }
        }

        i++;
        swap(elements, i, end);

        return i;
    }

    private static <T extends Comparable<T>> void sort(T[] elements, int start, int end) {
        if (start >= end) {
            return;
        }

        int p = partition(elements, start, end);
        sort(elements, start, p - 1);
        sort(elements, p + 1, end);
    }

    public static <T extends Comparable<T>> void sort(T[] elements) {
        if (elements == null) {
            return;
        }

        sort(elements, 0, elements.length - 1);
    }

    public static void main(String[] args) {
        Integer[] elements = new Integer[] {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

        sort(elements);

        for (Integer v : elements) {
            System.out.println(v);
        }
    }
}
