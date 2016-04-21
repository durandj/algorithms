public class InsertionSort {
    public static <T extends Comparable<T>> void sort(T[] elements) {
        for (int i = 1; i < elements.length; i++) {
            int currentIndex = i;

            for (int j = i - 1; j >= 0; j--) {
                if (elements[currentIndex].compareTo(elements[j]) < 0) {
                    T tmp = elements[currentIndex];
                    elements[currentIndex] = elements[j];
                    elements[j] = tmp;

                    currentIndex--;
                }
            }
        }
    }
}
