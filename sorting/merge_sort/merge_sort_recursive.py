def merge_sort(elements):
    length = len(elements)

    if length <= 1:
        return elements
    elif length == 2:
        if elements[0] > elements[1]:
            elements[0], elements[1] = elements[1], elements[0]

        return elements

    midpoint = length // 2
    sorted_list = []

    left = merge_sort([elements[i] for i in range(midpoint)])
    right = merge_sort([elements[i] for i in range(midpoint, length)])

    left_index = 0
    right_index = 0
    while left_index < midpoint and right_index < length - midpoint:
        if left[left_index] < right[right_index]:
            sorted_list.append(left[left_index])
            left_index += 1
        else:
            sorted_list.append(right[right_index])
            right_index += 1

    while left_index < midpoint:
        sorted_list.append(left[left_index])
        left_index += 1

    while right_index < length - midpoint:
        sorted_list.append(right[right_index])
        right_index += 1

    return sorted_list

