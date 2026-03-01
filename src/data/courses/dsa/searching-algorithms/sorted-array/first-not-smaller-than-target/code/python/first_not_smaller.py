def first_not_smaller(nums, target):
    """
    Find first element >= target in sorted array
    Time: O(log n), Space: O(1)
    """
    left, right = 0, len(nums)
    
    while left < right:
        mid = left + (right - left) // 2
        
        if nums[mid] < target:
            left = mid + 1   # Answer is in right half
        else:
            right = mid      # Answer might be here or left
    
    return nums[left] if left < len(nums) else -1

if __name__ == "__main__":
    nums = [1, 3, 5, 7, 9, 11, 13]
    target = 6
    
    result = first_not_smaller(nums, target)
    print(f"First element >= {target}: {result}")  # Output: 7
