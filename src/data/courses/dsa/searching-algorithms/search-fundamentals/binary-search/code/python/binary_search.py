def binary_search(nums, target):
    """
    Binary search - divide and conquer on sorted array
    Time: O(log n), Space: O(1)
    """
    left, right = 0, len(nums) - 1
    
    while left <= right:
        mid = left + (right - left) // 2
        
        if nums[mid] == target:
            return mid
        elif nums[mid] < target:
            left = mid + 1  # Search right half
        else:
            right = mid - 1  # Search left half
    
    return -1

if __name__ == "__main__":
    nums = [1, 3, 5, 7, 9, 11, 13]
    target = 7
    
    result = binary_search(nums, target)
    print(f"Index: {result}")  # Output: 3
