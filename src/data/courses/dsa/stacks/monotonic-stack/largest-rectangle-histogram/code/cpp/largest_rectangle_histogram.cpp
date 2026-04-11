// ============================================================
// Largest Rectangle in Histogram
// ============================================================

#include <vector>
#include <stack>
using namespace std;

// ============================================================
// Solution 1: Brute Force — All Pairs
// Time: O(N²) | Space: O(1)
// ============================================================
class Solution1 {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        for (int i = 0; i < heights.size(); i++) {
            int minH = heights[i];
            for (int j = i; j < heights.size(); j++) {
                minH = min(minH, heights[j]);
                maxArea = max(maxArea, minH * (j - i + 1));
            }
        }
        return maxArea;
    }
};

// ============================================================
// Solution 2: Monotonic Increasing Stack (Optimal)
// Time: O(N) | Space: O(N)
// ============================================================
class Solution2 {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        st.push(-1); // Left sentinel
        int maxArea = 0;

        for (int i = 0; i <= n; i++) {
            // Use height 0 at the end to force all bars to pop
            int h = (i == n) ? 0 : heights[i];

            while (st.top() != -1 && h <= heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();

                // Width: from left boundary (new top) to right boundary (i)
                int width = i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }

            st.push(i);
        }

        return maxArea;
    }
};
