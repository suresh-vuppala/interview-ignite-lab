// ============================================================
// Max Stack
// ============================================================

#include <stack>
#include <algorithm>
using namespace std;

class MaxStack {
    stack<int> mainStack;
    stack<int> maxStack;
public:
    void push(int val) {
        mainStack.push(val);
        maxStack.push(maxStack.empty() ? val : max(val, maxStack.top()));
    }
    void pop() { mainStack.pop(); maxStack.pop(); }
    int top() { return mainStack.top(); }
    int getMax() { return maxStack.top(); }
};
