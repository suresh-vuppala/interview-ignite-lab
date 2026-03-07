def merge_sort(arr):
    """Sort array using merge sort algorithm"""
    if len(arr) <= 1:
        return arr
    
    mid = len(arr) // 2
    left = merge_sort(arr[:mid])
    right = merge_sort(arr[mid:])
    
    return merge(left, right)


def merge(left, right):
    """Merge two sorted arrays"""
    result = []
    i = j = 0
    
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1
    
    result.extend(left[i:])
    result.extend(right[j:])
    return result


def merge_sort_in_place(arr, left=0, right=None):
    """Sort array in-place using merge sort"""
    if right is None:
        right = len(arr) - 1
    
    if left >= right:
        return
    
    mid = left + (right - left) // 2
    merge_sort_in_place(arr, left, mid)
    merge_sort_in_place(arr, mid + 1, right)
    merge_in_place(arr, left, mid, right)


def merge_in_place(arr, left, mid, right):
    """Merge two sorted subarrays in-place"""
    L = arr[left:mid+1]
    R = arr[mid+1:right+1]
    
    i = j = 0
    k = left
    
    while i < len(L) and j < len(R):
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
