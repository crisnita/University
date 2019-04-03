lst = [64, 25, 12, 22, 11]

lst2 = [['2', '1/2/1321', '15:20', 'bac'], ['1', '1/1/1344', '11:20', 'ala']]


def sort(l, key = lambda x : x, reverse = False):
    return sorted(l, key = key, reverse = reverse)


#print(sort(lst, reverse = True))

def swap(lst, a, b):
    aux = lst[a]
    lst[a] = lst[b]
    lst[b] = aux
    return lst

def selectionSort(lst, key = lambda x: x, reverse = False):
    for firstElem in range(len(lst)-1):
        minim = firstElem
        for i in range(firstElem+1, len(lst)):
            if lst[i] < lst[minim]:
                minim = i
        if minim != firstElem:
            swap(lst, minim, firstElem)

    if reverse == True:
        for i in range(len(lst)//2):
            aux = lst[i]
            lst[i] = lst[len(lst) - i - 1]
            lst[len(lst) - i - 1] = aux

    return lst


def selectionSort2(lst, key=lambda x: x[3], reverse = False):
    for firstElem in range(len(lst)-1):
        minim = firstElem
        for i in range(firstElem+1, len(lst)):
            if key(lst[i]) < key(lst[minim]):
                minim = i
        if minim != firstElem:
            swap(lst, minim, firstElem)

    if reverse == True:
        for i in range(len(lst)//2):
            aux = lst[i]
            lst[i] = lst[len(lst) - i - 1]
            lst[len(lst) - i - 1] = aux

    return lst


def shakeSort(lst, key=lambda x: x[3], reverse=False):
    lun = len(lst)
    start = 0
    end = lun-1
    swapped = True
    while swapped is True:
        swapped = False
        for i in range(start, end):
            if key(lst[i]) > key(lst[i+1]):
                lst[i], lst[i+1] = lst[i+1], lst[i]     # swaps the items
                swapped = True
        if swapped is False:
            break

        swapped = False
        end = end-1
        for i in range(end, start, -1):
            if key(lst[i]) < key(lst[i-1]):
                lst[i], lst[i-1] = lst[i-1], lst[i]
                swapped = True
        if swapped is False:
            break

        start = start+1

    if reverse is True:
        for i in range(lun//2):
            lst[i], lst[lun-i-1] = lst[lun-i-1], lst[i]
    return lst



lst2 = shakeSort(lst2, key=lambda x: x[2])

print(lst2)
