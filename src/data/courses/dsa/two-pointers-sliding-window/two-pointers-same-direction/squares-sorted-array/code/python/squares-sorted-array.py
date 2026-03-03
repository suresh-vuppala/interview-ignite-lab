def sorted_squares(nums):
    n = len(nums)
    res = [0] * n
    l, r, k = 0, n - 1, n - 1
    while l <= r:
        if abs(nums[l]) > abs(nums[r]):
            res[k] = nums[l] * nums[l]
            l += 1
        else:
            res[k] = nums[r] * nums[r]
            r -= 1
        k -= 1
    return res