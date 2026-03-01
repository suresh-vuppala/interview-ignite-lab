def find_peak(nums):
    """
    Find peak index in a mountain array
    Time: O(log n), Space: O(1)
    """
    left, right = 0, len(nums) - 1
    
    while left < right:
        mid = left + (right - left) // 2
        
        # If we're on uphill side, peak is to the right
        if nums[mid] < nums[mid + 1]:
            left = mid + 1
        else:
            # We're on downhill side or at peak
            right = mid
    
    return left

if __name__ == "__main__":
    nums1 = [1, 3, 5, 4, 2]
    print(f"Peak index: {find_peak(nums1)}")  # Output: 2
    print(f"Peak value: {nums1[find_peak(nums1)]}")  # Output: 5
    
    nums2 = [0, 10, 5, 2]
    print(f"Peak index: {find_peak(nums2)}")  # Output: 1
    print(f"Peak value: {nums2[find_peak(nums2)]}")  # Output: 10
