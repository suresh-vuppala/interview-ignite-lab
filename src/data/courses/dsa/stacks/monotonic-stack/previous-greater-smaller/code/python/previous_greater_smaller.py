class PreviousGreaterSmaller:
    def previousGreater(self, nums: list[int]) -> list[int]:
        n = len(nums)
        result = [0] * n
        stack = []
        
        for i in range(n):
            while stack and stack[-1] <= nums[i]:
                stack.pop()
            result[i] = -1 if not stack else stack[-1]
            stack.append(nums[i])
        
        return result
    
    def previousSmaller(self, nums: list[int]) -> list[int]:
        n = len(nums)
        result = [0] * n
        stack = []
        
        for i in range(n):
            while stack and stack[-1] >= nums[i]:
                stack.pop()
            result[i] = -1 if not stack else stack[-1]
            stack.append(nums[i])
        
        return result
