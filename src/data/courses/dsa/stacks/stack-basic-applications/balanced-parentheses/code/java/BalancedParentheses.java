// ============================================================
// Valid Parentheses (Balanced Brackets)
// ============================================================

import java.util.*;

// ============================================================
// Solution 1: Brute Force — Repeatedly Remove Pairs
// Time: O(N²) | Space: O(N)
// ============================================================
class Solution1 {
    public boolean isValid(String s) {
        String prev = "";
        while (!s.equals(prev)) {
            prev = s;
            s = s.replace("()", "").replace("[]", "").replace("{}", "");
        }
        return s.isEmpty();
    }
}

// ============================================================
// Solution 2: Stack — Single Pass (Optimal)
// Time: O(N) | Space: O(N)
// ============================================================
class Solution2 {
    public boolean isValid(String s) {
        Deque<Character> stack = new ArrayDeque<>();
        Map<Character, Character> match = Map.of(')', '(', ']', '[', '}', '{');

        for (char c : s.toCharArray()) {
            if (c == '(' || c == '[' || c == '{') {
                stack.push(c);
            } else {
                if (stack.isEmpty() || stack.peek() != match.get(c)) return false;
                stack.pop();
            }
        }

        return stack.isEmpty();
    }
}
