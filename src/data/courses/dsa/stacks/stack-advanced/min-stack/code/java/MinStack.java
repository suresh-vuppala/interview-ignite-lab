// ============================================================
// Min Stack
// ============================================================

import java.util.*;

// ============================================================
// Solution 1: Two Stacks
// All operations O(1)
// ============================================================
class MinStack1 {
    Deque<Integer> main = new ArrayDeque<>();
    Deque<Integer> min = new ArrayDeque<>();

    public void push(int val) {
        main.push(val);
        min.push(min.isEmpty() ? val : Math.min(val, min.peek()));
    }

    public void pop() { main.pop(); min.pop(); }
    public int top() { return main.peek(); }
    public int getMin() { return min.peek(); }
}

// ============================================================
// Solution 2: Optimized Min Stack
// All operations O(1)
// ============================================================
class MinStack2 {
    Deque<Integer> main = new ArrayDeque<>();
    Deque<Integer> min = new ArrayDeque<>();

    public void push(int val) {
        main.push(val);
        if (min.isEmpty() || val <= min.peek()) min.push(val);
    }

    public void pop() {
        if (main.peek().equals(min.peek())) min.pop();
        main.pop();
    }

    public int top() { return main.peek(); }
    public int getMin() { return min.peek(); }
}
