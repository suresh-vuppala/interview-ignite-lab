public class SquareRoot {
    /**
     * Find integer square root (floor of sqrt)
     * Time: O(log n), Space: O(1)
     */
    public static int squareRoot(int n) {
        if (n < 2) return n;
        
        int left = 0, right = n;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            long square = (long) mid * mid;
            
            if (square == n) {
                return mid;
            } else if (square < n) {
                left = mid + 1;  // Answer is larger
            } else {
                right = mid - 1; // Answer is smaller
            }
        }
        
        return right;  // Largest integer whose square <= n
    }

    public static void main(String[] args) {
        System.out.println(squareRoot(16));  // Output: 4
        System.out.println(squareRoot(17));  // Output: 4
        System.out.println(squareRoot(25));  // Output: 5
    }
}
