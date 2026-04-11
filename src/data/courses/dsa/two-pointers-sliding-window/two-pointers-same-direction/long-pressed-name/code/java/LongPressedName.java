// ============================================================
// Long Pressed Name
// ============================================================

// ============================================================
// Solution: Two Pointers
// Time: O(N+M) | Space: O(1)
// ============================================================
class Solution {
    public boolean isLongPressedName(String name, String typed) {
        int i = 0, j = 0;

        while (j < typed.length()) {
            if (i < name.length() && name.charAt(i) == typed.charAt(j)) {
                i++; j++;
            } else if (j > 0 && typed.charAt(j) == typed.charAt(j - 1)) {
                j++;  // Long press
            } else {
                return false;
            }
        }

        return i == name.length();
    }
}
