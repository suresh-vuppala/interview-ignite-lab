# ==================== SOLUTION 1: BRUTE FORCE ====================
# Time: O(N²) | Space: O(1)

def majority_element_brute(nums):
    n = len(nums)
    for num in nums:
        count = sum(1 for x in nums if x == num)
        if count > n // 2:
            return num
    return -1


# ==================== SOLUTION 2: HASHMAP ====================
# Time: O(N) | Space: O(N)

def majority_element_hashmap(nums):
    n = len(nums)
    freq = {}
    
    for num in nums:
        freq[num] = freq.get(num, 0) + 1
        if freq[num] > n // 2:
            return num
    
    return -1


# ==================== SOLUTION 3: SORTING ====================
# Time: O(N log N) | Space: O(1) or O(N)

def majority_element_sorting(nums):
    nums.sort()
    return nums[len(nums) // 2]


# ==================== SOLUTION 4: BOYER-MOORE VOTING ====================
# Time: O(N) | Space: O(1)

def majority_element_boyer_moore(nums):
    """
    Boyer-Moore Voting Algorithm.
    
    Maintain candidate and count. Cancel out different elements.
    Final candidate is the majority element.
    """
    candidate = None
    count = 0
    
    for num in nums:
        if count == 0:
            candidate = num
            count = 1
        elif num == candidate:
            count += 1
        else:
            count -= 1
    
    return candidate


# ==================== SOLUTION 5: RANDOMIZED ====================
# Time: O(N) expected | Space: O(1)

import random

def majority_element_randomized(nums):
    n = len(nums)
    
    while True:
        candidate = random.choice(nums)
        count = sum(1 for x in nums if x == candidate)
        if count > n // 2:
            return candidate


# ==================== MAIN SOLUTION (RECOMMENDED) ====================

def majorityElement(nums):
    """
    Find the majority element (appears > n/2 times).
    
    Time: O(N) - single pass
    Space: O(1) - only two variables
    
    Uses Boyer-Moore Voting Algorithm - optimal solution.
    
    Example:
        >>> majorityElement([3, 2, 3])
        3
        >>> majorityElement([2, 2, 1, 1, 1, 2, 2])
        2
    """
    return majority_element_boyer_moore(nums)
