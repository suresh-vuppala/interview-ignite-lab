# Time: O(1) | Space: O(1)

def check_bit(n, k):
    return (n & (1 << k)) != 0

def set_bit(n, k):
    return n | (1 << k)

def unset_bit(n, k):
    return n & ~(1 << k)

def toggle_bit(n, k):
    return n ^ (1 << k)