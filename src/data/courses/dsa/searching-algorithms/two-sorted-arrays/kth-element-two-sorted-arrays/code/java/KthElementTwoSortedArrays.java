// Time: O(log(min(m, n)))
// Space: O(1)

public class KthElementTwoSortedArrays {
    /**
     * Find kth element of two sorted arrays
     */
    public static int kthElement(int[] nums1, int[] nums2, int k) {
        int m = nums1.length, n = nums2.length;
        
        if (m > n) {
            return kthElement(nums2, nums1, k);
        }
        
        int low = Math.max(0, k - n);
        int high = Math.min(k, m);
        
        while (low <= high) {
            int cut1 = (low + high) / 2;
            int cut2 = k - cut1;
            
            int left1 = (cut1 == 0) ? Integer.MIN_VALUE : nums1[cut1 - 1];
            int right1 = (cut1 == m) ? Integer.MAX_VALUE : nums1[cut1];
            int left2 = (cut2 == 0) ? Integer.MIN_VALUE : nums2[cut2 - 1];
            int right2 = (cut2 == n) ? Integer.MAX_VALUE : nums2[cut2];
            
            if (left1 <= right2 && left2 <= right1) {
                return Math.max(left1, left2);
            } else if (left1 > right2) {
                high = cut1 - 1;
            } else {
                low = cut1 + 1;
            }
        }
        
        return -1;
    }
    
    public static void main(String[] args) {
        int[] nums1 = {2, 3, 6, 7, 9};
        int[] nums2 = {1, 4, 8, 10};
        int k = 5;
        
        int result = kthElement(nums1, nums2, k);
        System.out.println("Kth element: " + result); // Output: 6
    }
}
