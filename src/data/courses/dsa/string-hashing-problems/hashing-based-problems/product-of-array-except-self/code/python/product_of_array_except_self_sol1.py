class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        # Brute Force: O(n²) — Multiply all others for each
        n = len(nums)
        result = [1] * n
        for i in range(n):
            for j in range(n):
                if i != j: result[i] *= nums[j]
        return result