def has_subarray_sum(nums, k, target):
    window_sum = 0
    for i in range(len(nums)):
        window_sum += nums[i]
        if i >= k: window_sum -= nums[i - k]
        if i >= k - 1 and window_sum == target: return True
    return False