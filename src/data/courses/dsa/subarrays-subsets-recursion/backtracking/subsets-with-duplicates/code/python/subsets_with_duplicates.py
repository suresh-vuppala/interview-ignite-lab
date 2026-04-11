class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        nums.sort(); result = []
        def backtrack(start, cur):
            result.append(cur[:])
            for i in range(start, len(nums)):
                if i > start and nums[i] == nums[i-1]: continue  # Skip duplicates
                cur.append(nums[i]); backtrack(i+1, cur); cur.pop()
        backtrack(0, []); return result