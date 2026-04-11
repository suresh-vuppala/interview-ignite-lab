def distinct_in_window(nums, k):
    return [len(set(nums[i:i+k])) for i in range(len(nums)-k+1)]