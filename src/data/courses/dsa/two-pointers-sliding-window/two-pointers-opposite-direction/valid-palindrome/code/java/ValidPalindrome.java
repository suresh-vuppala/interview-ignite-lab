// ============================================================
// Valid Palindrome
// ============================================================

// ============================================================
// Solution 1: Filter + Reverse
// Time: O(N) | Space: O(N)
// ============================================================
class Solution1 {
    public boolean isPalindrome(String s) {
        StringBuilder clean = new StringBuilder();
        for (char c : s.toCharArray()) {
            if (Character.isLetterOrDigit(c)) {
                clean.append(Character.toLowerCase(c));
            }
        }
        return clean.toString().equals(clean.reverse().toString());
    }
}

// ============================================================
// Solution 2: Two Pointers In-Place (Optimal)
// Time: O(N) | Space: O(1)
// ============================================================
class Solution2 {
    public boolean isPalindrome(String s) {
        int left = 0, right = s.length() - 1;

        while (left < right) {
            while (left < right && !Character.isLetterOrDigit(s.charAt(left))) left++;
            while (left < right && !Character.isLetterOrDigit(s.charAt(right))) right--;

            if (Character.toLowerCase(s.charAt(left)) != Character.toLowerCase(s.charAt(right))) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
}
