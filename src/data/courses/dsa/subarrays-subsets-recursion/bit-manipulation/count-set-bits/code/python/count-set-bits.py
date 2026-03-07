# Time: O(log N) naive, O(K) Brian Kernighan | Space: O(1)

def count_set_bits_naive(n):
    count = 0
    while n:
        count += n & 1
        n >>= 1
    return count

def count_set_bits_optimal(n):
    count = 0
    while n:
        n &= n - 1
        count += 1
    return count