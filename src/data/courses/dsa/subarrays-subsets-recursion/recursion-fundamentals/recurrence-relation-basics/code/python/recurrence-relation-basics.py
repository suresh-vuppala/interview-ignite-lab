# T(n) = T(n-1) + O(1) -> O(n)
def linear(n):
    if n == 0:
        return 0
    return 1 + linear(n-1)

# T(n) = 2T(n-1) + O(1) -> O(2^n)
def exponential(n):
    if n == 0:
        return 1
    return exponential(n-1) + exponential(n-1)

# T(n) = 2T(n/2) + O(n) -> O(n log n)
def divide(n):
    if n <= 1:
        return
    divide(n//2)
    divide(n//2)