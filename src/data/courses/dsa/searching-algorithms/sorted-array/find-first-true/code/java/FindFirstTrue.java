public class FindFirstTrue {
    /**
     * Find first true in sorted boolean array
     * Time: O(log n), Space: O(1)
     */
    public static int findFirstTrue(boolean[] arr) {
        int left = 0, right = arr.length - 1;
        int result = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (arr[mid]) {
                result = mid;  // Record this as potential answer
                right = mid - 1; // Continue searching left
            } else {
                left = mid + 1;  // Search right
            }
        }
        
        return result;
    }

    public static void main(String[] args) {
        boolean[] arr = {false, false, false, true, true, true};
        
        int result = findFirstTrue(arr);
        System.out.println("Index: " + result); // Output: 3
    }
}
