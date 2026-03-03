def count_subarrays(arr):
    n = len(arr)
    return n * (n + 1) // 2

def count_subsequences(arr):
    return (1 << len(arr)) - 1