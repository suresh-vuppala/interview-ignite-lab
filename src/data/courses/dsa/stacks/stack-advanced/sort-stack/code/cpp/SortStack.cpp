#include <stack>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
    // ==================== SOLUTION 1: USING TEMPORARY STACK ====================
    // Time: O(n²) | Space: O(n)
    stack<int> sortStackWithTemp(stack<int> st) {
        stack<int> temp;
        
        while (!st.empty()) {
            // Pop element from input stack
            int current = st.top();
            st.pop();
            
            // Move elements from temp to input that are greater than current
            while (!temp.empty() && temp.top() > current) {
                st.push(temp.top());
                temp.pop();
            }
            
            // Push current to temp in sorted position
            temp.push(current);
        }
        
        // Transfer back to original stack
        while (!temp.empty()) {
            st.push(temp.top());
            temp.pop();
        }
        
        return st;
    }
    
    // ==================== SOLUTION 2: RECURSIVE APPROACH ====================
    // Time: O(n²) | Space: O(n)
    stack<int> sortStackRecursive(stack<int> st) {
        // Base case: empty stack
        if (st.empty()) {
            return st;
        }
        
        // Pop top element
        int temp = st.top();
        st.pop();
        
        // Recursively sort remaining stack
        st = sortStackRecursive(st);
        
        // Insert popped element in sorted position
        st = insertSorted(st, temp);
        
        return st;
    }
    
    stack<int> insertSorted(stack<int> st, int element) {
        // Base case: empty stack or element is largest
        if (st.empty() || st.top() <= element) {
            st.push(element);
            return st;
        }
        
        // Pop top and recursively insert element
        int temp = st.top();
        st.pop();
        st = insertSorted(st, element);
        
        // Push back the popped element
        st.push(temp);
        return st;
    }
    
    // ==================== SOLUTION 3: USING ARRAY AND SORTING ====================
    // Time: O(n log n) | Space: O(n)
    stack<int> sortStackWithArray(stack<int> st) {
        // Transfer to vector
        vector<int> arr;
        while (!st.empty()) {
            arr.push_back(st.top());
            st.pop();
        }
        
        // Sort array
        sort(arr.begin(), arr.end());
        
        // Push back in reverse order (largest first)
        for (int i = arr.size() - 1; i >= 0; i--) {
            st.push(arr[i]);
        }
        
        return st;
    }
    
    // ==================== SOLUTION 4: USING PRIORITY QUEUE (MIN HEAP) ====================
    // Time: O(n log n) | Space: O(n)
    stack<int> sortStackWithHeap(stack<int> st) {
        // Transfer to min heap
        priority_queue<int, vector<int>, greater<int>> heap;
        while (!st.empty()) {
            heap.push(st.top());
            st.pop();
        }
        
        // Transfer to temp stack (smallest first)
        stack<int> temp;
        while (!heap.empty()) {
            temp.push(heap.top());
            heap.pop();
        }
        
        // Transfer back to original (largest on top)
        while (!temp.empty()) {
            st.push(temp.top());
            temp.pop();
        }
        
        return st;
    }
    
    // ==================== MAIN SOLUTION (RECOMMENDED) ====================
    // Using Array + Sort for best time complexity
    stack<int> sortStack(stack<int> st) {
        return sortStackWithArray(st);
    }
};
