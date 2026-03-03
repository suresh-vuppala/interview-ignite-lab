# Comparison-based: Merge Sort
def merge_sort(arr, l, r):
    if l < r:
        m = l + (r - l) // 2
        merge_sort(arr, l, m)
        merge_sort(arr, m + 1, r)
        merge(arr, l, m, r)

# Non-comparison: Counting Sort
def counting_sort(arr, k):
    count = [0] * (k + 1)
    for x in arr:
        count[x] += 1
    idx = 0
    for i in range(k + 1):
        while count[i] > 0:
            arr[idx] = i
            idx += 1
            count[i] -= 1