#include <vector>
#include <utility>

template <typename T>
std::vector<T> merge_sort(const std::vector<T> &elements) {
    auto size = elements.size();

    if (size <= 1) {
        return elements;
    }
    else if (size == 2) {
        if (elements[0] > elements[1]) {
            return std::vector<T>{elements[1], elements[0]};
        }

        return elements;
    }

    auto midpoint = size / 2;

    auto begin = elements.begin();
    auto end = elements.end();

    auto left = merge_sort(std::vector<T>(begin, begin + midpoint));
    auto right = merge_sort(std::vector<T>(begin + midpoint, end));

    auto left_index = 0;
    auto right_index = 0;
    std::vector<T> sorted;

    while (left_index < midpoint && right_index < size - midpoint) {
        if (left[left_index] < right[right_index]) {
            sorted.push_back(left[left_index]);
            left_index++;
        }
        else {
            sorted.push_back(right[right_index]);
            right_index++;
        }
    }

    while (left_index < midpoint) {
        sorted.push_back(left[left_index]);
        left_index++;
    }

    while (right_index < size - midpoint) {
        sorted.push_back(right[right_index]);
        right_index++;
    }

    return sorted;
}

