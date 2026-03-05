class NextGreaterElementII:
    def nextGreaterElements(self, nums: list[int]) -> list[int]:
        n = len(nums)
        result = [-1] * n
        stack = []
        
        # Traverse twice for circular array
        for i in range(2 * n):
            idx = i % n
            while stack and nums[stack[-1]] < nums[idx]:
                result[stack.pop()] = nums[idx]
            if i < n:
                stack.append(idx)  # Push only in first pass
        
        return result
