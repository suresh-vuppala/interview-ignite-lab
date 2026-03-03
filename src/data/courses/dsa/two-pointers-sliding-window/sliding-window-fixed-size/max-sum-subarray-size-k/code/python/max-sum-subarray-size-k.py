def max_sum(arr, k):
    s = 0
    max_sum = float('-inf')
    for i in range(len(arr)):
        s += arr[i]
        if i >= k - 1:
            max_sum = max(max_sum, s)
            s -= arr[i - k + 1]
    return max_sum