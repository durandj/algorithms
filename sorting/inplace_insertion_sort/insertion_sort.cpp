#include <array>
#include <utility>

template <typename T>
void insertion_sort(T *elements, std::size_t size) {
    if (elements == nullptr) {
        return;
    }

    for (auto i = 1ul; i < size; i++) {
        auto cur_index = i;

        for (auto j = 0ul; j < i; j++) {
            auto cmp_index = i - 1 - j;

            if (elements[cur_index] < elements[cmp_index]) {
                std::swap(elements[cmp_index], elements[cur_index]);
                cur_index--;
            }
        }
    }
}
