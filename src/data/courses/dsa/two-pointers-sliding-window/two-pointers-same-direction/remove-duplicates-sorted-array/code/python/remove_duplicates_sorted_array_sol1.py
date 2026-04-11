class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        # Extra Array: O(n) space
        unique = [nums[0]]
        for i in range(1, len(nums)):
            if nums[i] != unique[-1]: unique.append(nums[i])
        for i in range(len(unique)): nums[i] = unique[i]
        return len(unique)