def longest_subarray(nums, k):
    max_len = 0
    for i in range(len(nums)):
        s = 0
        for j in range(i, len(nums)):
            s += nums[j]
            if s <= k: max_len = max(max_len, j-i+1)
            else: break
    return max_len