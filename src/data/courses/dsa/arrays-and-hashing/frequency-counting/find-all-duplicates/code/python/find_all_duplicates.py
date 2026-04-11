class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        # O(n) time, O(1) space — Negate at index to mark visited
        result = []
        for num in nums:
            idx = abs(num) - 1
            if nums[idx] < 0:
                result.append(idx + 1)  # Already visited = duplicate
            else:
                nums[idx] = -nums[idx]  # Mark as visited
        return result