from collections import deque
def first_negative(nums, k):
    neg_idx, result = deque(), []
    for i in range(len(nums)):
        if nums[i] < 0: neg_idx.append(i)
        if i >= k - 1:
            while neg_idx and neg_idx[0] < i-k+1: neg_idx.popleft()
            result.append(nums[neg_idx[0]] if neg_idx else 0)
    return result