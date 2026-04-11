# ============================================================
# 4Sum
# ============================================================

from typing import List

# ============================================================
# Solution 1: Brute Force — All Quadruplets
# Time: O(N⁴) | Space: O(1)
# ============================================================
class Solution1:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums.sort()
        result = set()
        n = len(nums)
        for i in range(n-3):
            for j in range(i+1,n-2):
                for k in range(j+1,n-1):
                    for l in range(k+1,n):
                        if nums[i]+nums[j]+nums[k]+nums[l]==target:
                            result.add((nums[i],nums[j],nums[k],nums[l]))
        return [list(t) for t in result]

# ============================================================
# Solution 2: Sort + Two Nested Loops + Two Pointers (Optimal)
# Time: O(N³) | Space: O(1) extra
# ============================================================
class Solution2:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums.sort()
        result = []
        n = len(nums)

        for i in range(n - 3):
            if i > 0 and nums[i] == nums[i-1]: continue

            for j in range(i+1, n-2):
                if j > i+1 and nums[j] == nums[j-1]: continue

                left, right = j+1, n-1
                while left < right:
                    total = nums[i]+nums[j]+nums[left]+nums[right]

                    if total == target:
                        result.append([nums[i],nums[j],nums[left],nums[right]])
                        while left<right and nums[left]==nums[left+1]: left+=1
                        while left<right and nums[right]==nums[right-1]: right-=1
                        left+=1; right-=1
                    elif total < target: left+=1
                    else: right-=1

        return result
