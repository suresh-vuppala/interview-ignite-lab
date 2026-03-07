def longest_subarray(nums, k):
    left = s = max_len = 0
    for right in range(len(nums)):
        s += nums[right]
        while s > k:
            s -= nums[left]
            left += 1
        max_len = max(max_len, right - left + 1)
    return max_len