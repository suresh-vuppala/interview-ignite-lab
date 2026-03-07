import java.util.*;

class Solution {
    // ==================== SOLUTION 1: BRUTE FORCE ====================
    // Time: O(n×k) | Space: O(1)
    public int[] maxSlidingWindowBruteForce(int[] arr, int k) {
        int n = arr.length;
        int[] result = new int[n - k + 1];
        
        // For each window
        for (int i = 0; i <= n - k; i++) {
            // Find max in window
            int windowMax = arr[i];
            for (int j = i; j < i + k; j++) {
                windowMax = Math.max(windowMax, arr[j]);
            }
            result[i] = windowMax;
        }
        
        return result;
    }
    
    // ==================== SOLUTION 2: MONOTONIC DEQUE - OPTIMAL ====================
    // Time: O(n) | Space: O(k)
    public int[] maxSlidingWindowDeque(int[] arr, int k) {
        int n = arr.length;
        int[] result = new int[n - k + 1];
        Deque<Integer> dq = new LinkedList<>();  // Store indices in decreasing order
        
        for (int i = 0; i < n; i++) {
            // Remove indices outside current window
            while (!dq.isEmpty() && dq.peek() <= i - k) {
                dq.poll();
            }
            
            // Remove indices with smaller values (can't be max)
            while (!dq.isEmpty() && arr[dq.peekLast()] < arr[i]) {
                dq.pollLast();
            }
            
            // Add current index
            dq.offer(i);
            
            // Add max to result (after first window is complete)
            if (i >= k - 1) {
                result[i - k + 1] = arr[dq.peek()];
            }
        }
        
        return result;
    }
    
    // ==================== SOLUTION 3: USING MAX HEAP ====================
    // Time: O(n log k) | Space: O(k)
    public int[] maxSlidingWindowHeap(int[] arr, int k) {
        int n = arr.length;
        int[] result = new int[n - k + 1];
        PriorityQueue<int[]> heap = new PriorityQueue<>((a, b) -> b[0] - a[0]);  // Max heap
        
        // Add first k elements
        for (int i = 0; i < k; i++) {
            heap.offer(new int[]{arr[i], i});
        }
        
        result[0] = heap.peek()[0];
        
        // Process remaining elements
        for (int i = k; i < n; i++) {
            // Add new element
            heap.offer(new int[]{arr[i], i});
            
            // Remove elements outside window
            while (!heap.isEmpty() && heap.peek()[1] <= i - k) {
                heap.poll();
            }
            
            // Top is maximum
            result[i - k + 1] = heap.peek()[0];
        }
        
        return result;
    }
    
    // ==================== MAIN SOLUTION (RECOMMENDED) ====================
    public int[] maxSlidingWindow(int[] arr, int k) {
        return maxSlidingWindowDeque(arr, k);
    }
}
