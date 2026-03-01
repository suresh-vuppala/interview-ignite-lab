public class FirstNotSmaller {
    /**
     * Find first element >= target in sorted array
     * Time: O(log n), Space: O(1)
     */
    public static int firstNotSmaller(int[] nums, int target) {
        int left = 0, right = nums.length;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] < target) {
                left = mid + 1;   // Answer is in right half
            } else {
                right = mid;      // Answer might be here or left
            }
        }
        
        return left < nums.length ? nums[left] : -1;
    }

    public static void main(String[] args) {
        int[] nums = {1, 3, 5, 7, 9, 11, 13};
        int target = 6;
        
        int result = firstNotSmaller(nums, target);
        System.out.println("First element >= " + target + ": " + result); // Output: 7
    }
}
