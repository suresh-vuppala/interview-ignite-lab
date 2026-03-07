def kth_element(nums1, nums2, k):
    """
    Find kth element of two sorted arrays
    Time: O(log(min(m, n))), Space: O(1)
    """
    m, n = len(nums1), len(nums2)
    
    if m > n:
        return kth_element(nums2, nums1, k)
    
    low = max(0, k - n)
    high = min(k, m)
    
    while low <= high:
        cut1 = (low + high) // 2
        cut2 = k - cut1
        
        left1 = float('-inf') if cut1 == 0 else nums1[cut1 - 1]
        right1 = float('inf') if cut1 == m else nums1[cut1]
        left2 = float('-inf') if cut2 == 0 else nums2[cut2 - 1]
        right2 = float('inf') if cut2 == n else nums2[cut2]
        
        if left1 <= right2 and left2 <= right1:
            return max(left1, left2)
        elif left1 > right2:
            high = cut1 - 1
        else:
            low = cut1 + 1
    
    return -1

if __name__ == "__main__":
    nums1 = [2, 3, 6, 7, 9]
    nums2 = [1, 4, 8, 10]
    k = 5
    
    result = kth_element(nums1, nums2, k)
    print(f"Kth element: {result}")  # Output: 6
