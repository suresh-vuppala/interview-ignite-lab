// ============================================================
// Backspace String Compare
// ============================================================

// ============================================================
// Solution 1: Stack — Build Processed Strings
// Time: O(N+M) | Space: O(N+M)
// ============================================================
class Solution1 {
    public boolean backspaceCompare(String s, String t) {
        return process(s).equals(process(t));
    }

    private String process(String str) {
        StringBuilder sb = new StringBuilder();
        for (char c : str.toCharArray()) {
            if (c == '#') { if (sb.length() > 0) sb.deleteCharAt(sb.length()-1); }
            else sb.append(c);
        }
        return sb.toString();
    }
}

// ============================================================
// Solution 2: Two Pointers from End (Optimal)
// Time: O(N+M) | Space: O(1)
// ============================================================
class Solution2 {
    public boolean backspaceCompare(String s, String t) {
        int i = s.length()-1, j = t.length()-1;
        while (i >= 0 || j >= 0) {
            i = getNext(s, i); j = getNext(t, j);
            if (i >= 0 && j >= 0 && s.charAt(i) != t.charAt(j)) return false;
            if ((i >= 0) != (j >= 0)) return false;
            i--; j--;
        }
        return true;
    }

    private int getNext(String s, int i) {
        int skip = 0;
        while (i >= 0) {
            if (s.charAt(i) == '#') { skip++; i--; }
            else if (skip > 0) { skip--; i--; }
            else break;
        }
        return i;
    }
}
