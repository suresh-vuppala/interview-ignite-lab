def merge_sort(arr, l, r):
    if l >= r:
        return 0
    m = l + (r - l) // 2
    count = merge_sort(arr, l, m) + merge_sort(arr, m + 1, r)
    return count + merge(arr, l, m, r)

def merge(arr, l, m, r):
    L = arr[l:m+1]
    R = arr[m+1:r+1]
    i = j = 0
    k = l
    count = 0
    while i < len(L) and j < len(R):
        count += 1
        if L[i] <= R[j]:
            arr[k] = L[i]
            i += 1
        else:
            arr[k] = R[j]
            j += 1
        k += 1
    while i < len(L):
        arr[k] = L[i]
        i += 1
        k += 1
    while j < len(R):
        arr[k] = R[j]
        j += 1
        k += 1
    return count