// Time: O(N × 2^N), Space: O(N)

import java.util.*;

class Solution {
    public List<List<String>> partition(String s) {
        List<List<String>> result = new ArrayList<>();
        backtrack(s, 0, new ArrayList<>(), result);
        return result;
    }
    
    private void backtrack(String s, int index, List<String> current, List<List<String>> result) {
        if (index == s.length()) {
            result.add(new ArrayList<>(current));
            return;
        }
        
        for (int end = index; end < s.length(); end++) {
            if (isPalindrome(s, index, end)) {
                current.add(s.substring(index, end + 1));
                backtrack(s, end + 1, current, result);
                current.remove(current.size() - 1);
            }
        }
    }
    
    private boolean isPalindrome(String s, int left, int right) {
        while (left < right) {
            if (s.charAt(left++) != s.charAt(right--)) return false;
        }
        return true;
    }
}

public class PalindromePartitioning {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.partition("aab"));
    }
}
