import java.util.*;

class Solution {
    // ==================== SOLUTION 1: BRUTE FORCE ====================
    // Time: O(n×k) | Space: O(1)
    public List<Integer> firstNegativeBruteForce(int[] arr, int k) {
        int n = arr.length;
        List<Integer> result = new ArrayList<>();
        
        // For each window
        for (int i = 0; i <= n - k; i++) {
            // Find first negative in window
            int firstNeg = 0;
            for (int j = i; j < i + k; j++) {
                if (arr[j] < 0) {
                    firstNeg = arr[j];
                    break;
                }
            }
            result.add(firstNeg);
        }
        
        return result;
    }
    
    // ==================== SOLUTION 2: SLIDING WINDOW WITH DEQUE - OPTIMAL ====================
    // Time: O(n) | Space: O(k)
    public List<Integer> firstNegativeDeque(int[] arr, int k) {
        int n = arr.length;
        List<Integer> result = new ArrayList<>();
        Deque<Integer> dq = new LinkedList<>();  // Store indices of negative numbers
        
        // Process first window
        for (int i = 0; i < k; i++) {
            if (arr[i] < 0) {
                dq.offer(i);
            }
        }
        
        // First window result
        result.add(dq.isEmpty() ? 0 : arr[dq.peek()]);
        
        // Process remaining windows
        for (int i = k; i < n; i++) {
            // Remove indices outside current window
            while (!dq.isEmpty() && dq.peek() <= i - k) {
                dq.poll();
            }
            
            // Add current element if negative
            if (arr[i] < 0) {
                dq.offer(i);
            }
            
            // First negative in current window
            result.add(dq.isEmpty() ? 0 : arr[dq.peek()]);
        }
        
        return result;
    }
    
    // ==================== MAIN SOLUTION (RECOMMENDED) ====================
    public List<Integer> firstNegative(int[] arr, int k) {
        return firstNegativeDeque(arr, k);
    }
}
