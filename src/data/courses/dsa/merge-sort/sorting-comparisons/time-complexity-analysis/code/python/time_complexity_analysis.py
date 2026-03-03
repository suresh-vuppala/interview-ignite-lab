# Merge Sort: O(n log n)
def merge_sort(arr, l, r):
    if l < r:
        m = l + (r - l) // 2
        merge_sort(arr, l, m)      # T(n/2)
        merge_sort(arr, m + 1, r)  # T(n/2)
        merge(arr, l, m, r)        # O(n)
# T(n) = 2T(n/2) + O(n) = O(n log n)

# Quick Sort: O(n log n) avg, O(n²) worst
def quick_sort(arr, l, r):
    if l < r:
        p = partition(arr, l, r)
        quick_sort(arr, l, p - 1)
        quick_sort(arr, p + 1, r)