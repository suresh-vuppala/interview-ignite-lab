def subarray_sum(arr, k):
    res = []
    s = 0
    for i in range(len(arr)):
        s += arr[i]
        if i >= k - 1:
            res.append(s)
            s -= arr[i - k + 1]
    return res