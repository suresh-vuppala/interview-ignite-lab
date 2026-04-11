// ============================================================
// Next Greater Element
// ============================================================

#include <vector>
#include <stack>
using namespace std;

// ============================================================
// Solution 1: Brute Force — Scan Right
// Time: O(N²) | Space: O(1)
// ============================================================
class Solution1 {
public:
    vector<int> nextGreaterElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[j] > nums[i]) {
                    result[i] = nums[j]; // First greater to the right
                    break;
                }
            }
        }

        return result;
    }
};

// ============================================================
// Solution 2: Monotonic Decreasing Stack (Optimal)
// Time: O(N) | Space: O(N)
// ============================================================
class Solution2 {
public:
    vector<int> nextGreaterElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);
        stack<int> st; // Stores indices — decreasing by value

        for (int i = 0; i < n; i++) {
            // Current element is NGE for all smaller stack elements
            while (!st.empty() && nums[i] > nums[st.top()]) {
                result[st.top()] = nums[i]; // Found NGE
                st.pop();
            }

            st.push(i); // This element now waits for its NGE
        }

        return result;
    }
};
