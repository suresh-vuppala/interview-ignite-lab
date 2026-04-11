def find_pair(nums, target):
    nums.sort()
    i, j = 0, 1
    while i < len(nums) and j < len(nums):
        if i == j: j += 1; continue
        d = nums[j] - nums[i]
        if d == target: return True
        if d < target: j += 1
        else: i += 1
    return False