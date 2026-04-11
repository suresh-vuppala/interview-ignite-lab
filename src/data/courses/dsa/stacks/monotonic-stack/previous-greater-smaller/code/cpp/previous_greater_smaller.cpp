// ============================================================
// Previous Greater and Previous Smaller Element
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
    vector<int> previousGreater(vector<int>& nums) {
        int n = nums.size(); vector<int> result(n, -1);
        for (int i = 1; i < n; i++)
            for (int j = i-1; j >= 0; j--)
                if (nums[j] > nums[i]) { result[i] = nums[j]; break; }
        return result;
    }
    vector<int> previousSmaller(vector<int>& nums) {
        int n = nums.size(); vector<int> result(n, -1);
        for (int i = 1; i < n; i++)
            for (int j = i-1; j >= 0; j--)
                if (nums[j] < nums[i]) { result[i] = nums[j]; break; }
        return result;
    }
};

// ============================================================
// Solution 2: Monotonic Stack (Optimal)
// Time: O(N) | Space: O(N)
// ============================================================
class Solution2 {
public:
    // PGE: Monotonic decreasing stack
    vector<int> previousGreater(vector<int>& nums) {
        int n = nums.size(); vector<int> result(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] <= nums[i]) st.pop();
            if (!st.empty()) result[i] = nums[st.top()]; // Top = PGE
            st.push(i);
        }
        return result;
    }

    // PSE: Monotonic increasing stack
    vector<int> previousSmaller(vector<int>& nums) {
        int n = nums.size(); vector<int> result(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] >= nums[i]) st.pop();
            if (!st.empty()) result[i] = nums[st.top()]; // Top = PSE
            st.push(i);
        }
        return result;
    }
};
