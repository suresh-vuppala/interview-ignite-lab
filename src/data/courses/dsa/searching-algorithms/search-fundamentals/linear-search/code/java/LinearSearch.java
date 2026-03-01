public class LinearSearch {
    /**
     * Linear search - scan elements sequentially until target found
     * Time: O(n), Space: O(1)
     */
    public static int linearSearch(int[] nums, int target) {
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == target) {
                return i;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        int[] nums = {3, 1, 4, 1, 5, 9, 2, 6};
        int target = 5;
        
        int result = linearSearch(nums, target);
        System.out.println("Index: " + result); // Output: 4
    }
}
