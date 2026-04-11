// ============================================================
// Min Stack
// ============================================================

#include <stack>
#include <algorithm>
using namespace std;

// ============================================================
// Solution 1: Two Stacks — Main + Min Stack
// All operations O(1) | Space: O(2N)
// ============================================================
class MinStack1 {
    stack<int> mainStack;
    stack<int> minStack;

public:
    MinStack1() {}

    void push(int val) {
        mainStack.push(val);
        // Min stack tracks minimum at each level
        if (minStack.empty()) {
            minStack.push(val);
        } else {
            minStack.push(min(val, minStack.top()));
        }
    }

    void pop() {
        mainStack.pop();
        minStack.pop(); // Both stacks stay in sync
    }

    int top() {
        return mainStack.top();
    }

    int getMin() {
        return minStack.top(); // O(1) minimum access
    }
};

// ============================================================
// Solution 2: Optimized — Push Min Only When Needed
// All operations O(1) | Space: O(N) average
// ============================================================
class MinStack2 {
    stack<int> mainStack;
    stack<int> minStack;

public:
    MinStack2() {}

    void push(int val) {
        mainStack.push(val);
        // Only push when val is new minimum (or equal)
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }

    void pop() {
        // Only pop min when main's value matches current min
        if (mainStack.top() == minStack.top()) {
            minStack.pop();
        }
        mainStack.pop();
    }

    int top() { return mainStack.top(); }
    int getMin() { return minStack.top(); }
};
