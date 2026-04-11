class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        # O(n) time, O(1) extra space — Two-pass approach
        n = len(nums)
        result = [1] * n
        
        # Pass 1: Left products (result[i] = product of all elements to the left)
        left = 1
        for i in range(n):
            result[i] = left
            left *= nums[i]
        
        # Pass 2: Multiply by right products
        right = 1
        for i in range(n - 1, -1, -1):
            result[i] *= right
            right *= nums[i]
        
        return result