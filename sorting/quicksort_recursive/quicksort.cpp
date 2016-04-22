#include <utility>

#include <iostream>

template <typename T>
std::size_t partition(T *elements, std::size_t start, std::size_t end) {
    T *value = elements + end;
    std::size_t i = start - 1;

    for (auto p = start; p < end; p++) {
        if (elements[p] <= *value) {
            i++;
            std::swap(elements[i], elements[p]);
        }
    }

    i++;
    std::swap(elements[i], elements[end]);

    return i;
}

template <typename T>
void quicksort(T *elements, std::size_t start, std::size_t end) {
    if (elements == nullptr) {
        return;
    }

    if (start >= end) {
        return;
    }

    auto p = partition(elements, start, end);

    if (p != start) {
        quicksort(elements, start, p - 1);
    }

    if (p != end) {
        quicksort(elements, p + 1, end);
    }
}

template <typename T>
void quicksort(T *elements, std::size_t size) {
    if (elements == nullptr) {
        return;
    }

    quicksort(elements, 0, size - 1);
}

int main(void) {
    int elements[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    quicksort(elements, 10);

    for (auto v : elements) {
        std::cout << v << " ";
    }
    std::cout << std::endl;

    return 0;
}
