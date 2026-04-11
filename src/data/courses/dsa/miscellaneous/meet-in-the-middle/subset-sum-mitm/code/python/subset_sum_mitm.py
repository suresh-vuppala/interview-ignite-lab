from bisect import bisect_left
def closest_subset_sum(nums, target):
    n = len(nums); half = n // 2
    left = [sum(nums[i] for i in range(half) if mask & (1<<i)) for mask in range(1<<half)]
    right = sorted(sum(nums[half+i] for i in range(n-half) if mask & (1<<i)) for mask in range(1<<(n-half)))
    best = float('inf')
    for s in left:
        need = target - s
        idx = bisect_left(right, need)
        if idx < len(right): best = min(best, abs(s + right[idx] - target))
        if idx > 0: best = min(best, abs(s + right[idx-1] - target))
    return best