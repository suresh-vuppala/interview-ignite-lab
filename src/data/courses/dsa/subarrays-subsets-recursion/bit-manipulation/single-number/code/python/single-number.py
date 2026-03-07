# Time: O(N) | Space: O(1)

def single_number(nums):
    result = 0
    for num in nums:
        result ^= num
    return result