# Time: O(1) per operation | Space: O(1)

# Demonstrate all 6 bitwise operators
def demonstrate_operators(a, b):
    print(f"AND: {a} & {b} = {a & b}")
    print(f"OR: {a} | {b} = {a | b}")
    print(f"XOR: {a} ^ {b} = {a ^ b}")
    print(f"NOT: ~{a} = {~a}")
    print(f"Left Shift: {a} << 2 = {a << 2}")
    print(f"Right Shift: {a} >> 1 = {a >> 1}")

# Basic bit operations
def check_bit(n, k):
    return (n & (1 << k)) != 0

def set_bit(n, k):
    return n | (1 << k)

def clear_bit(n, k):
    return n & ~(1 << k)

def toggle_bit(n, k):
    return n ^ (1 << k)

def rightmost_set_bit(n):
    return n & -n

def clear_rightmost_set_bit(n):
    return n & (n - 1)

def is_power_of_2(n):
    return n > 0 and (n & (n - 1)) == 0

def count_set_bits(n):
    count = 0
    while n:
        n &= n - 1
        count += 1
    return count

def find_single_number(arr):
    result = 0
    for num in arr:
        result ^= num
    return result