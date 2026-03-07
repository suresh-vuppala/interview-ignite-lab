import java.util.*;

public class TwoDifference {
    
    // ==================== SOLUTION 1: BRUTE FORCE ====================
    // Time: O(N²) | Space: O(1)
    public static boolean twoDifferenceBrute(int[] arr, int k) {
        int n = arr.length;
        // Check all pairs
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (arr[j] - arr[i] == k) {  // Found pair with difference k
                    return true;
                }
            }
        }
        return false;
    }
    
    // ==================== SOLUTION 2: TWO POINTERS ====================
    // Time: O(N) | Space: O(1)
    public static boolean twoDifferenceTwoPointers(int[] arr, int k) {
        int n = arr.length;
        int left = 0, right = 1;
        
        while (right < n) {
            int diff = arr[right] - arr[left];
            
            // Found the pair
            if (diff == k && left != right) {
                return true;
            }
            
            // Difference too small, move right pointer
            if (diff < k) {
                right++;
            }
            // Difference too large, move left pointer
            else {
                left++;
            }
            
            // Ensure pointers don't overlap
            if (left == right) {
                right++;
            }
        }
        
        return false;
    }
    
    // ==================== SOLUTION 3: HASHSET ====================
    // Time: O(N) | Space: O(N)
    public static boolean twoDifferenceHashSet(int[] arr, int k) {
        Set<Integer> seen = new HashSet<>();
        
        for (int num : arr) {
            // Check if num + k or num - k exists
            if (seen.contains(num + k) || seen.contains(num - k)) {
                return true;
            }
            seen.add(num);
        }
        
        return false;
    }
    
    // ==================== SOLUTION 4: BINARY SEARCH ====================
    // Time: O(N log N) | Space: O(1)
    public static boolean twoDifferenceBinarySearch(int[] arr, int k) {
        // For each element, search for element + k
        for (int i = 0; i < arr.length; i++) {
            if (binarySearch(arr, i + 1, arr[i] + k)) {
                return true;
            }
        }
        return false;
    }
    
    private static boolean binarySearch(int[] arr, int start, int target) {
        int left = start, right = arr.length - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) {
                return true;
            } else if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }
    
    // Main solution - recommended approach
    public static boolean twoDifference(int[] arr, int k) {
        return twoDifferenceTwoPointers(arr, k);
    }
}
