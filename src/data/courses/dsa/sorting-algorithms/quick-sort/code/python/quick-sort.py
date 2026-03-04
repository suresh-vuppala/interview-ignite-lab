def quick_sort(arr, low, high):
    if low < high:
        pi = partition(arr, low, high)  # Get partition index
        quick_sort(arr, low, pi - 1)  # Sort left half
        quick_sort(arr, pi + 1, high)  # Sort right half

def partition(arr, low, high):
    pivot = arr[high]  # Choose last element as pivot
    i = low - 1  # Index of smaller element
    for j in range(low, high):
        if arr[j] < pivot:  # If current element is smaller than pivot
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    arr[i + 1], arr[high] = arr[high], arr[i + 1]  # Place pivot in correct position
    return i + 1