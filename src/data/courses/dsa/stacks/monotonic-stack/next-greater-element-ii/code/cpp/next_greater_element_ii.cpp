// ============================================================
// Next Greater Element II (Circular)
// ============================================================

#include <vector>
#include <stack>
using namespace std;

// ============================================================
// Solution 1: Brute Force
// Time: O(N²) | Space: O(1)
// ============================================================
class Solution1 {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);
        for (int i = 0; i < n; i++)
            for (int j = 1; j < n; j++)
                if (nums[(i+j) % n] > nums[i]) { result[i] = nums[(i+j)%n]; break; }
        return result;
    }
};

// ============================================================
// Solution 2: Monotonic Stack + Double Pass (Optimal)
// Time: O(N) | Space: O(N)
// ============================================================
class Solution2 {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);
        stack<int> st;

        // Iterate twice to simulate circular
        for (int i = 0; i < 2 * n; i++) {
            while (!st.empty() && nums[i % n] > nums[st.top()]) {
                result[st.top()] = nums[i % n];
                st.pop();
            }
            if (i < n) st.push(i); // Only push in first pass
        }

        return result;
    }
};
