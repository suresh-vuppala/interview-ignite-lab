class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        # Optimal: O(n) time, O(1) extra space
        n = len(nums)
        result = [1] * n
        left = 1
        for i in range(n):
            result[i] = left
            left *= nums[i]
        right = 1
        for i in range(n-1, -1, -1):
            result[i] *= right
            right *= nums[i]
        return result