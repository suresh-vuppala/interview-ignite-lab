public class PeakOfMountain {
    /**
     * Find peak index in a mountain array
     * Time: O(log n), Space: O(1)
     */
    public static int findPeak(int[] nums) {
        int left = 0, right = nums.length - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            // If we're on uphill side, peak is to the right
            if (nums[mid] < nums[mid + 1]) {
                left = mid + 1;
            } else {
                // We're on downhill side or at peak
                right = mid;
            }
        }
        
        return left;
    }

    public static void main(String[] args) {
        int[] nums1 = {1, 3, 5, 4, 2};
        System.out.println("Peak index: " + findPeak(nums1));  // Output: 2
        System.out.println("Peak value: " + nums1[findPeak(nums1)]);  // Output: 5
        
        int[] nums2 = {0, 10, 5, 2};
        System.out.println("Peak index: " + findPeak(nums2));  // Output: 1
        System.out.println("Peak value: " + nums2[findPeak(nums2)]);  // Output: 10
    }
}
