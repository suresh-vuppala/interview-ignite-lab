def find_kth_smallest(arr, k):
    return quick_select(arr, 0, len(arr) - 1, k - 1)  # k-1 because 0-indexed

def quick_select(arr, low, high, k):
    pi = partition(arr, low, high)  # Partition array
    if pi == k:
        return arr[pi]  # Found kth smallest
    if pi > k:
        return quick_select(arr, low, pi - 1, k)  # Search left
    return quick_select(arr, pi + 1, high, k)  # Search right

def partition(arr, low, high):
    pivot = arr[high]
    i = low - 1
    for j in range(low, high):
        if arr[j] < pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1