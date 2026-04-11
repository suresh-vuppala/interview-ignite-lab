// ============================================================
// Max Stack
// ============================================================

import java.util.*;

class MaxStack {
    Deque<Integer> main = new ArrayDeque<>();
    Deque<Integer> max = new ArrayDeque<>();

    public void push(int val) {
        main.push(val);
        max.push(max.isEmpty() ? val : Math.max(val, max.peek()));
    }
    public void pop() { main.pop(); max.pop(); }
    public int top() { return main.peek(); }
    public int getMax() { return max.peek(); }
}
