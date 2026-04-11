def can_partition(nums):
    total = sum(nums)
    if total % 2: return False
    target = total // 2
    n = len(nums); h = n // 2
    left = {sum(nums[i] for i in range(h) if m & (1<<i)) for m in range(1<<h)}
    for m in range(1<<(n-h)):
        s = sum(nums[h+i] for i in range(n-h) if m & (1<<i))
        if target - s in left: return True
    return False