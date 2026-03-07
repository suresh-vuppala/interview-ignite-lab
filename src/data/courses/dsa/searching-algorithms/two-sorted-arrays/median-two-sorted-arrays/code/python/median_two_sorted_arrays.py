def find_median_sorted_arrays(nums1, nums2):
    """
    Find median of two sorted arrays
    Time: O(log(min(m, n))), Space: O(1)
    """
    if len(nums1) > len(nums2):
        nums1, nums2 = nums2, nums1
    
    m, n = len(nums1), len(nums2)
    low, high = 0, m
    
    while low <= high:
        cut1 = (low + high) // 2
        cut2 = (m + n + 1) // 2 - cut1
        
        left1 = float('-inf') if cut1 == 0 else nums1[cut1 - 1]
        right1 = float('inf') if cut1 == m else nums1[cut1]
        left2 = float('-inf') if cut2 == 0 else nums2[cut2 - 1]
        right2 = float('inf') if cut2 == n else nums2[cut2]
        
        if left1 <= right2 and left2 <= right1:
            if (m + n) % 2 == 1:
                return max(left1, left2)
            return (max(left1, left2) + min(right1, right2)) / 2.0
        elif left1 > right2:
            high = cut1 - 1
        else:
            low = cut1 + 1
    
    return 0.0

if __name__ == "__main__":
    nums1 = [1, 3]
    nums2 = [2]
    
    result = find_median_sorted_arrays(nums1, nums2)
    print(f"Median: {result}")  # Output: 2.0
