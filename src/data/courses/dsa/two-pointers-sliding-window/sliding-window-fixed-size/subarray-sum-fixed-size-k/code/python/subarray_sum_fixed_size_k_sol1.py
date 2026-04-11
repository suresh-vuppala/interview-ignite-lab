def has_subarray_sum(nums, k, target):
    for i in range(len(nums) - k + 1):
        if sum(nums[i:i+k]) == target: return True
    return False