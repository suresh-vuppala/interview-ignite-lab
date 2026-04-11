from typing import List

# ==================== SOLUTION 1: BRUTE FORCE ====================
# Time: O(N²) | Space: O(1)
# Check every pair of elements for the target sum
def twoSumBrute(nums: List[int], target: int) -> List[int]:
    n = len(nums)
    
    # Try all pairs (i, j) where i < j
    for i in range(n - 1):
        for j in range(i + 1, n):
            # Check if this pair sums to target
            if nums[i] + nums[j] == target:
                return [i, j]
    
    return []


# ==================== SOLUTION 2: HASH MAP — ONE PASS ====================
# Time: O(N) | Space: O(N)
# Store seen numbers in dict, look up complement in O(1)
def twoSumHashMap(nums: List[int], target: int) -> List[int]:
    seen = {}  # value -> index
    
    for i, num in enumerate(nums):
        complement = target - num
        
        # Check if complement was already seen
        if complement in seen:
            return [seen[complement], i]
        
        # Store current number for future lookups
        # (check BEFORE insert to avoid using same element twice)
        seen[num] = i
    
    return []


# Main solution - recommended approach
def twoSum(nums: List[int], target: int) -> List[int]:
    return twoSumHashMap(nums, target)
