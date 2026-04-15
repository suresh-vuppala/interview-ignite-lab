// Time: O(N * log(sum - max))
// Space: O(1)

class PaintersPartition {
    public static int paintersPartition(int[] boards, int m) {
        int n = boards.length;
        
        // Edge case: More painters than boards
        if (m > n) return -1;
        
        // Binary search range
        int low = getMax(boards);   // Minimum possible answer
        int high = getSum(boards);  // Maximum possible answer
        int result = high;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            // Check if we can paint with max time = mid
            if (canPaint(boards, n, m, mid)) {
                result = mid;      // This works, try smaller
                high = mid - 1;
            } else {
                low = mid + 1;     // Too small, need larger limit
            }
        }
        
        return result;
    }
    
    private static boolean canPaint(int[] boards, int n, int m, int maxTime) {
        int painterCount = 1;      // Start with first painter
        int currentTime = 0;       // Time assigned to current painter
        
        for (int i = 0; i < n; i++) {
            // If a single board takes more time than our limit, impossible
            if (boards[i] > maxTime) return false;
            
            // Try to assign current board to current painter
            if (currentTime + boards[i] <= maxTime) {
                currentTime += boards[i];  // Assign to current painter
            } else {
                // Current painter's limit reached, assign to next painter
                painterCount++;
                currentTime = boards[i];   // Start new painter with current board
                
                // If we need more painters than available, this limit is too small
                if (painterCount > m) return false;
            }
        }
        
        // Successfully painted all boards within the limit
        return true;
    }
    
    private static int getMax(int[] arr) {
        int max = arr[0];
        for (int num : arr) max = Math.max(max, num);
        return max;
    }
    
    private static int getSum(int[] arr) {
        int sum = 0;
        for (int num : arr) sum += num;
        return sum;
    }
}
