def min_sub_array_len(target, nums):
    left = s = 0
    min_len = float('inf')
    for right in range(len(nums)):
        s += nums[right]
        while s >= target:
            min_len = min(min_len, right - left + 1)
            s -= nums[left]
            left += 1
    return 0 if min_len == float('inf') else min_len