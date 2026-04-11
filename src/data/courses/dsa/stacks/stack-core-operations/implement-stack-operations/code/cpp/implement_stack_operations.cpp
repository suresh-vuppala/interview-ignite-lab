// ============================================================
// Implement Stack Operations
// ============================================================

#include <vector>
#include <stdexcept>
using namespace std;

// ============================================================
// Solution: Array-Based Stack
// All operations O(1) amortized
// ============================================================
class MyStack {
private:
    vector<int> data;

public:
    // Push element onto stack — O(1) amortized
    void push(int x) {
        data.push_back(x);
    }

    // Remove and return top element — O(1)
    int pop() {
        if (isEmpty()) throw runtime_error("Stack underflow");
        int top = data.back();
        data.pop_back();
        return top;
    }

    // Return top element without removing — O(1)
    int top() {
        if (isEmpty()) throw runtime_error("Stack is empty");
        return data.back();
    }

    // Check if stack is empty — O(1)
    bool isEmpty() {
        return data.empty();
    }

    // Return number of elements — O(1)
    int size() {
        return data.size();
    }
};
