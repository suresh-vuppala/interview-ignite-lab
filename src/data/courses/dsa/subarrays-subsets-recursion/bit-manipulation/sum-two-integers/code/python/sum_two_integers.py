class Solution:
    def getSum(self, a: int, b: int) -> int:
        # Python handles arbitrary precision, need 32-bit mask
        MASK = 0xFFFFFFFF; MAX = 0x7FFFFFFF
        while b & MASK:
            carry = a & b
            a = a ^ b
            b = carry << 1
        return a & MASK if a > MAX else a & MASK
        # Handle negative numbers in Python's unlimited int