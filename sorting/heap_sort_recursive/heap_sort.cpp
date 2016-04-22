#include <utility>

inline std::size_t parent_index(const std::size_t index) {
    return index / 2;
}

inline std::size_t left_index(const std::size_t index) {
    return index * 2;
}

inline std::size_t right_index(const std::size_t index) {
    return index * 2 + 1;
}

template <typename T>
void heapify(T *elements, const std::size_t parent, const std::size_t size) {
    std::size_t left = left_index(parent);
    std::size_t right = right_index(parent);
    std::size_t largest = parent;

    if (left < size && elements[parent] < elements[left]) {
        largest = left;
    }

    if (right < size && elements[largest] < elements[right]) {
        largest = right;
    }

    if (largest != parent) {
        std::swap(elements[parent], elements[largest]);
        heapify(elements, largest, size);
    }
}

template <typename T>
void heap_sort(T *elements, const std::size_t size) {
    if (elements == nullptr) {
        return;
    }

    auto heap_size = parent_index(size - 1);
    for (auto i = 0ul; i <= heap_size; i++) {
        heapify(elements, heap_size - i, size);
    }

    for (auto i = 0ul; i < size; i++) {
        auto index = size - i - 1;

        std::swap(elements[0], elements[index]);
        heapify(elements, 0, index);
    }
}
