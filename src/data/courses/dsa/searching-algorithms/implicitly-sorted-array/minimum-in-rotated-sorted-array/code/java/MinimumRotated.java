public class MinimumRotated {
    /**
     * Find minimum in rotated sorted array
     * Time: O(log n), Space: O(1)
     */
    public static int findMin(int[] nums) {
        int left = 0, right = nums.length - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            // If mid > right, rotation point is in right half
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                // Mid is in the sorted portion or at minimum
                right = mid;
            }
        }
        
        return nums[left];
    }

    public static void main(String[] args) {
        int[] arr1 = {3, 4, 5, 1, 2};
        System.out.println("Min in [3,4,5,1,2]: " + findMin(arr1));  // Output: 1

        int[] arr2 = {2, 1};
        System.out.println("Min in [2,1]: " + findMin(arr2));  // Output: 1

        int[] arr3 = {1, 3};
        System.out.println("Min in [1,3]: " + findMin(arr3));  // Output: 1
    }
}
