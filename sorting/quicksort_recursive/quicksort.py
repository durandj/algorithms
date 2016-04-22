def partition(elements, start, end):
    value = elements[end]
    i = start - 1

    for p in range(start, end):
        if elements[p] <= value:
            i += 1
            elements[i], elements[p] = elements[p], elements[i]

    i += 1
    elements[i], elements[end] = elements[end], elements[i]

    return i

def quicksort(elements, start = 0, size = None):
    if size is None:
        size = len(elements) - 1

    if size == 0 or start >= size:
        return

    p = partition(elements, start, size)
    quicksort(elements, start, p - 1)
    quicksort(elements, p + 1, size)

a = list(reversed(range(11)))
quicksort(a)

print(a)
