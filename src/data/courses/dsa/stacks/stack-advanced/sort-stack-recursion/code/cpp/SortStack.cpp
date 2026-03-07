#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

// Time: O(N²), Space: O(N)
class SortStack {
public:
    void sortStackBruteForce(stack<int>& st) {
        vector<int> temp;
        while (!st.empty()) {
            temp.push_back(st.top());
            st.pop();
        }
        sort(temp.begin(), temp.end(), greater<int>());
        for (int val : temp) st.push(val);
    }

    // ============================================================

    // Time: O(N²), Space: O(N)
    void sortStackTempStack(stack<int>& st) {
        stack<int> temp;
        while (!st.empty()) {
            int curr = st.top();
            st.pop();
            while (!temp.empty() && temp.top() > curr) {
                st.push(temp.top());
                temp.pop();
            }
            temp.push(curr);
        }
        while (!temp.empty()) {
            st.push(temp.top());
            temp.pop();
        }
    }

    // ============================================================

    // Time: O(N²), Space: O(N)
    void sortStackRecursionHelper(stack<int>& st) {
        if (st.empty()) return;
        int temp = st.top();
        st.pop();
        sortStackRecursionHelper(st);
        insertSorted(st, temp);
    }

private:
    void insertSorted(stack<int>& st, int element) {
        if (st.empty() || st.top() <= element) {
            st.push(element);
            return;
        }
        int temp = st.top();
        st.pop();
        insertSorted(st, element);
        st.push(temp);
    }

public:
    // ============================================================

    // Time: O(N²), Space: O(N)
    void sortStackRecursionInline(stack<int>& st) {
        if (st.empty()) return;
        int temp = st.top();
        st.pop();
        sortStackRecursionInline(st);
        insert(st, temp);
    }

private:
    void insert(stack<int>& st, int val) {
        if (st.empty() || st.top() <= val) {
            st.push(val);
        } else {
            int top = st.top();
            st.pop();
            insert(st, val);
            st.push(top);
        }
    }

public:
    // ============================================================

    // Time: O(N log N), Space: O(N)
    stack<int> sortStackMergeSort(stack<int> st) {
        if (st.size() <= 1) return st;
        
        int mid = st.size() / 2;
        vector<int> temp;
        while (!st.empty()) {
            temp.push_back(st.top());
            st.pop();
        }
        reverse(temp.begin(), temp.end());
        
        stack<int> left, right;
        for (int i = 0; i < mid; i++) left.push(temp[i]);
        for (int i = mid; i < temp.size(); i++) right.push(temp[i]);
        
        left = sortStackMergeSort(left);
        right = sortStackMergeSort(right);
        
        return merge(left, right);
    }

private:
    stack<int> merge(stack<int> left, stack<int> right) {
        stack<int> result;
        vector<int> temp;
        
        while (!left.empty() && !right.empty()) {
            if (left.top() <= right.top()) {
                temp.push_back(left.top());
                left.pop();
            } else {
                temp.push_back(right.top());
                right.pop();
            }
        }
        while (!left.empty()) {
            temp.push_back(left.top());
            left.pop();
        }
        while (!right.empty()) {
            temp.push_back(right.top());
            right.pop();
        }
        
        for (int val : temp) result.push(val);
        return result;
    }
};
