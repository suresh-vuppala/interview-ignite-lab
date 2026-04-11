class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        seen, result = set(), []
        for num in nums:
            if num in seen: result.append(num)
            else: seen.add(num)
        return result