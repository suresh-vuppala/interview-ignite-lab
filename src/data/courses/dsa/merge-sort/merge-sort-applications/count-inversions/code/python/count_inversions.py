def merge_sort(arr, l, r):
    if l >= r:
        return 0
    m = l + (r - l) // 2
    return merge_sort(arr, l, m) + merge_sort(arr, m + 1, r) + merge(arr, l, m, r)

def merge(arr, l, m, r):
    L = arr[l:m+1]
    R = arr[m+1:r+1]
    i = j = 0
    k = l
    inv = 0
    while i < len(L) and j < len(R):
        if L[i] <= R[j]:
            arr[k] = L[i]
            i += 1
        else:
            arr[k] = R[j]
            j += 1
            inv += len(L) - i
        k += 1
    while i < len(L):
        arr[k] = L[i]
        i += 1
        k += 1
    while j < len(R):
        arr[k] = R[j]
        j += 1
        k += 1
    return inv