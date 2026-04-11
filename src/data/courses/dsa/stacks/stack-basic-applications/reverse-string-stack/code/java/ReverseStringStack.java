// ============================================================
// Reverse String Using Stack
// ============================================================

import java.util.*;

// ============================================================
// Solution 1: Two-Pointer Swap
// Time: O(N) | Space: O(1)
// ============================================================
class Solution1 {
    public String reverseString(String s) {
        char[] arr = s.toCharArray();
        int l = 0, r = arr.length - 1;
        while (l < r) { char t = arr[l]; arr[l] = arr[r]; arr[r] = t; l++; r--; }
        return new String(arr);
    }
}

// ============================================================
// Solution 2: Stack — Push All, Pop All
// Time: O(N) | Space: O(N)
// ============================================================
class Solution2 {
    public String reverseString(String s) {
        Deque<Character> stack = new ArrayDeque<>();
        for (char c : s.toCharArray()) stack.push(c);

        StringBuilder sb = new StringBuilder();
        while (!stack.isEmpty()) sb.append(stack.pop());
        return sb.toString();
    }
}
