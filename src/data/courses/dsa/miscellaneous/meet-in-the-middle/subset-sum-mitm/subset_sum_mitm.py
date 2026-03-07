# Time: O(2^(n/2) * n/2), Space: O(2^(n/2))

def subsetSum(arr, target):
    n = len(arr)
    mid = n // 2
    
    def generate_sums(nums):
        sums = []
        for mask in range(1 << len(nums)):
            s = sum(nums[i] for i in range(len(nums)) if mask & (1 << i))
            sums.append(s)
        return sums
    
    left_sums = sorted(generate_sums(arr[:mid]))
    right_sums = generate_sums(arr[mid:])
    
    for right_sum in right_sums:
        need = target - right_sum
        left, right = 0, len(left_sums) - 1
        while left <= right:
            mid_val = (left + right) // 2
            if left_sums[mid_val] == need:
                return True
            elif left_sums[mid_val] < need:
                left = mid_val + 1
            else:
                right = mid_val - 1
    
    return False
