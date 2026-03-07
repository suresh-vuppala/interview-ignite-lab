import java.util.*;

public class DistinctElementsWindow {
    
    // ==================== SOLUTION 1: BRUTE FORCE ====================
    // Time: O(N×K) | Space: O(N)
    public static List<Integer> distinctElementsBrute(int[] arr, int k) {
        int n = arr.length;
        List<Integer> result = new ArrayList<>();
        
        // For each window
        for (int i = 0; i <= n - k; i++) {
            Set<Integer> distinct = new HashSet<>();
            // Add all elements in window to set
            for (int j = i; j < i + k; j++) {
                distinct.add(arr[j]);
            }
            result.add(distinct.size());
        }
        
        return result;
    }
    
    // ==================== SOLUTION 2: SLIDING WINDOW WITH HASHMAP ====================
    // Time: O(N) | Space: O(N)
    public static List<Integer> distinctElementsSliding(int[] arr, int k) {
        int n = arr.length;
        if (n < k) return new ArrayList<>();
        
        Map<Integer, Integer> freq = new HashMap<>();
        List<Integer> result = new ArrayList<>();
        
        // Build first window
        for (int i = 0; i < k; i++) {
            freq.put(arr[i], freq.getOrDefault(arr[i], 0) + 1);
        }
        result.add(freq.size());
        
        // Slide the window
        for (int i = k; i < n; i++) {
            // Remove leftmost element of previous window
            int leftElem = arr[i - k];
            freq.put(leftElem, freq.get(leftElem) - 1);
            if (freq.get(leftElem) == 0) {
                freq.remove(leftElem);
            }
            
            // Add new element to window
            freq.put(arr[i], freq.getOrDefault(arr[i], 0) + 1);
            
            // Count distinct elements
            result.add(freq.size());
        }
        
        return result;
    }
    
    // ==================== SOLUTION 3: OPTIMIZED SLIDING WINDOW ====================
    // Time: O(N) | Space: O(N)
    public static List<Integer> distinctElementsOptimized(int[] arr, int k) {
        int n = arr.length;
        
        // Edge cases
        if (k <= 0 || k > n) return new ArrayList<>();
        
        Map<Integer, Integer> freq = new HashMap<>();
        List<Integer> result = new ArrayList<>();
        
        // Process first window
        for (int i = 0; i < k; i++) {
            freq.put(arr[i], freq.getOrDefault(arr[i], 0) + 1);
        }
        result.add(freq.size());
        
        // Slide window from k to n-1
        for (int i = k; i < n; i++) {
            // Remove element going out of window
            int outElem = arr[i - k];
            freq.put(outElem, freq.get(outElem) - 1);
            if (freq.get(outElem) == 0) {
                freq.remove(outElem);
            }
            
            // Add element coming into window
            int inElem = arr[i];
            freq.put(inElem, freq.getOrDefault(inElem, 0) + 1);
            
            // Record distinct count
            result.add(freq.size());
        }
        
        return result;
    }
    
    // Main solution - recommended approach
    public static List<Integer> distinctElementsWindow(int[] arr, int k) {
        return distinctElementsSliding(arr, k);
    }
}
