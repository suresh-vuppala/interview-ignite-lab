public class MonotonicFunction {
    /**
     * Check if array is monotonic increasing or decreasing
     * Time: O(n), Space: O(1)
     */
    public static boolean isMonotonic(int[] nums) {
        boolean increasing = true, decreasing = true;
        
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] > nums[i - 1]) {
                decreasing = false;
            }
            if (nums[i] < nums[i - 1]) {
                increasing = false;
            }
        }
        
        return increasing || decreasing;
    }

    public static void main(String[] args) {
        int[] arr1 = {1, 2, 2, 3, 5, 5, 8};
        System.out.println("Is [1,2,2,3,5,5,8] monotonic? " + isMonotonic(arr1));  // true

        int[] arr2 = {8, 5, 5, 3, 2, 2, 1};
        System.out.println("Is [8,5,5,3,2,2,1] monotonic? " + isMonotonic(arr2));  // true

        int[] arr3 = {1, 3, 2, 4, 5};
        System.out.println("Is [1,3,2,4,5] monotonic? " + isMonotonic(arr3));  // false
    }
}
