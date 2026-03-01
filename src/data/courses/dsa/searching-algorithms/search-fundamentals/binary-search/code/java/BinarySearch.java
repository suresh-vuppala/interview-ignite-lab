public class BinarySearch {
    /**
     * Binary search - divide and conquer on sorted array
     * Time: O(log n), Space: O(1)
     */
    public static int binarySearch(int[] nums, int target) {
        int left = 0, right = nums.length - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;  // Search right half
            } else {
                right = mid - 1; // Search left half
            }
        }
        
        return -1;
    }

    public static void main(String[] args) {
        int[] nums = {1, 3, 5, 7, 9, 11, 13};
        int target = 7;
        
        int result = binarySearch(nums, target);
        System.out.println("Index: " + result); // Output: 3
    }
}
