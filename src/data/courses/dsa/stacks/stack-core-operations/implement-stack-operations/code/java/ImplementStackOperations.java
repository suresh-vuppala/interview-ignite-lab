// ============================================================
// Implement Stack Operations
// ============================================================

import java.util.*;

// ============================================================
// Solution: Array-Based Stack
// All operations O(1) amortized
// ============================================================
class MyStack {
    private List<Integer> data = new ArrayList<>();

    public void push(int x) {
        data.add(x); // O(1) amortized
    }

    public int pop() {
        return data.remove(data.size() - 1); // O(1)
    }

    public int top() {
        return data.get(data.size() - 1); // O(1)
    }

    public boolean isEmpty() {
        return data.isEmpty(); // O(1)
    }

    public int size() {
        return data.size(); // O(1)
    }
}
