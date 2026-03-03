from collections import deque

def first_negative(arr, k):
    res = []
    dq = deque()
    for i in range(len(arr)):
        if arr[i] < 0:
            dq.append(i)
        if i >= k - 1:
            while dq and dq[0] < i - k + 1:
                dq.popleft()
            res.append(arr[dq[0]] if dq else 0)
    return res