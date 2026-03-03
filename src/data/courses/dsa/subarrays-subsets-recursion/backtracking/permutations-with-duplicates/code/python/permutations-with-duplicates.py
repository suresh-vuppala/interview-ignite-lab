def permute_unique(nums):
    result = []
    nums.sort()
    used = [False] * len(nums)
    
    def backtrack(curr):
        if len(curr) == len(nums):
            result.append(curr[:])
            return
        for i in range(len(nums)):
            if used[i] or (i > 0 and nums[i] == nums[i-1] and not used[i-1]):
                continue
            used[i] = True
            curr.append(nums[i])
            backtrack(curr)
            curr.pop()
            used[i] = False
    
    backtrack([])
    return result