def subsets(nums):
    result = []
    
    def backtrack(start, curr):
        result.append(curr[:])
        for i in range(start, len(nums)):
            curr.append(nums[i])
            backtrack(i+1, curr)
            curr.pop()
    
    backtrack(0, [])
    return result