def max_sum_subarray(nums, k):
    return max(sum(nums[i:i+k]) for i in range(len(nums)-k+1))