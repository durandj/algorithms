def insertion_sort(elements):
    length = len(elements)

    for i in range(1, length):
        for j in reversed(range(i)):
            if elements[i] < elements[j]:
                elements[i], elements[j] = elements[j], elements[i]
                i -= 1
