# Time: O(N) | Space: O(1)

def two_non_repeating(nums):
    xor_all = 0
    for num in nums:
        xor_all ^= num
    rightmost = xor_all & -xor_all
    a = b = 0
    for num in nums:
        if num & rightmost:
            a ^= num
        else:
            b ^= num
    return [a, b]