# Time: O(2^(n/2) * n/2), Space: O(2^(n/2))

def canPartition(nums):
    total = sum(nums)
    if total % 2 != 0:
        return False
    
    target = total // 2
    n = len(nums)
    mid = n // 2
    
    def generate_sums(arr):
        sums = set()
        for mask in range(1 << len(arr)):
            s = sum(arr[i] for i in range(len(arr)) if mask & (1 << i))
            sums.add(s)
        return sums
    
    left_sums = generate_sums(nums[:mid])
    right_sums = generate_sums(nums[mid:])
    
    for right_sum in right_sums:
        if target - right_sum in left_sums:
            return True
    
    return False
