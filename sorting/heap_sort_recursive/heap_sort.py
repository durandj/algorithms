def parent_index(index):
    return index // 2

def left_index(index):
    return index * 2

def right_index(index):
    return index * 2 + 1

def heapify(elements, parent, size):
    left = left_index(parent)
    right = right_index(parent)

    largest = parent
    if left < size and elements[parent] < elements[left]:
        largest = left

    if right < size and elements[largest] < elements[right]:
        largest = right

    if largest != parent:
        elements[parent], elements[largest] = elements[largest], elements[parent]
        heapify(elements, largest, size)

def heap_sort(elements):
    size = len(elements)

    parent = parent_index(size - 1)
    while parent >= 0:
        heapify(elements, parent, size)
        parent -= 1

    for i in reversed(range(1, size)):
        elements[0], elements[i] = elements[i], elements[0]

        heapify(elements, 0, i)
