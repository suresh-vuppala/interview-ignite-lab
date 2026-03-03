class Solution {
    // Subarrays count
    int countSubarrays(int[] arr) {
        return arr.length * (arr.length + 1) / 2;
    }
    
    // Subsequences count
    int countSubsequences(int[] arr) {
        return (1 << arr.length) - 1;
    }
}