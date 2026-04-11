// ============================================================
// Celebrity Problem
// ============================================================

import java.util.*;

class Solution {
    // boolean knows(int a, int b) — provided

    public int findCelebrity(int n) {
        Deque<Integer> stack = new ArrayDeque<>();
        for (int i = 0; i < n; i++) stack.push(i);

        while (stack.size() > 1) {
            int a = stack.pop(), b = stack.pop();
            stack.push(knows(a, b) ? b : a);
        }

        int candidate = stack.pop();
        for (int i = 0; i < n; i++) {
            if (i == candidate) continue;
            if (knows(candidate, i) || !knows(i, candidate)) return -1;
        }
        return candidate;
    }
}
