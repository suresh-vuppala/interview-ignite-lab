# Time: O(2^(n/2) * n), Space: O(2^(n/2))

def minAbsDifference(nums, goal):
    n = len(nums)
    mid = n // 2
    
    def generate_sums(arr):
        sums = []
        for mask in range(1 << len(arr)):
            s = sum(arr[i] for i in range(len(arr)) if mask & (1 << i))
            sums.append(s)
        return sums
    
    left_sums = sorted(generate_sums(nums[:mid]))
    right_sums = generate_sums(nums[mid:])
    
    min_diff = abs(goal)
    
    for right_sum in right_sums:
        need = goal - right_sum
        idx = bisect_left(left_sums, need)
        
        if idx < len(left_sums):
            min_diff = min(min_diff, abs(left_sums[idx] + right_sum - goal))
        if idx > 0:
            min_diff = min(min_diff, abs(left_sums[idx - 1] + right_sum - goal))
    
    return min_diff
