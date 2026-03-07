# Time: O(N × N!), Space: O(N)

def permute(nums):
    result = []
    
    def backtrack(index):
        if index == len(nums):
            result.append(nums[:])
            return
        
        for i in range(index, len(nums)):
            nums[index], nums[i] = nums[i], nums[index]
            backtrack(index + 1)
            nums[index], nums[i] = nums[i], nums[index]
    
    backtrack(0)
    return result

nums = [1, 2, 3]
print(permute(nums))
