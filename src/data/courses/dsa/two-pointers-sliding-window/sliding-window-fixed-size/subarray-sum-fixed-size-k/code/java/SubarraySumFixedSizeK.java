import java.util.*;

class Solution {
    // ==================== SOLUTION 1: BRUTE FORCE ====================
    // Time: O(n×k) | Space: O(1)
    public List<int[]> subarraySumBruteForce(int[] arr, int k) {
        int n = arr.length;
        List<int[]> result = new ArrayList<>();
        
        // For each starting position
        for (int i = 0; i <= n - k; i++) {
            // Calculate sum of k elements
            int windowSum = 0;
            int[] window = new int[k + 1]; // k elements + sum
            for (int j = 0; j < k; j++) {
                windowSum += arr[i + j];
                window[j] = arr[i + j];
            }
            window[k] = windowSum;
            result.add(window);
        }
        
        return result;
    }
    
    // ==================== SOLUTION 2: SLIDING WINDOW - OPTIMAL ====================
    // Time: O(n) | Space: O(1)
    public List<int[]> subarraySumSlidingWindow(int[] arr, int k) {
        int n = arr.length;
        List<int[]> result = new ArrayList<>();
        
        // Calculate sum of first window
        int windowSum = 0;
        for (int i = 0; i < k; i++) {
            windowSum += arr[i];
        }
        int[] firstWindow = new int[k + 1];
        System.arraycopy(arr, 0, firstWindow, 0, k);
        firstWindow[k] = windowSum;
        result.add(firstWindow);
        
        // Slide window
        for (int i = k; i < n; i++) {
            // Remove leftmost element, add rightmost element
            windowSum = windowSum - arr[i - k] + arr[i];
            int[] window = new int[k + 1];
            System.arraycopy(arr, i - k + 1, window, 0, k);
            window[k] = windowSum;
            result.add(window);
        }
        
        return result;
    }
    
    // ==================== MAIN SOLUTION (RECOMMENDED) ====================
    public List<int[]> subarraySum(int[] arr, int k) {
        return subarraySumSlidingWindow(arr, k);
    }
}
