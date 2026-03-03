def check_bit(n, i):
    return (n & (1 << i)) != 0

def set_bit(n, i):
    return n | (1 << i)

def unset_bit(n, i):
    return n & ~(1 << i)

def toggle_bit(n, i):
    return n ^ (1 << i)