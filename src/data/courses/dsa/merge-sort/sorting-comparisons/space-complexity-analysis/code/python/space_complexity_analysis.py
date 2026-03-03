# Merge Sort: O(n) space
def merge(arr, l, m, r):
    L = arr[l:m+1]  # O(n) space
    R = arr[m+1:r+1]
    # ... merge logic

# Quick Sort: O(log n) space (recursion)
def quick_sort(arr, l, r):
    if l < r:
        p = partition(arr, l, r)
        quick_sort(arr, l, p - 1)
        quick_sort(arr, p + 1, r)

# Heap Sort: O(1) space
def heap_sort(arr):
    n = len(arr)
    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)
    for i in range(n - 1, 0, -1):
        arr[0], arr[i] = arr[i], arr[0]
        heapify(arr, i, 0)