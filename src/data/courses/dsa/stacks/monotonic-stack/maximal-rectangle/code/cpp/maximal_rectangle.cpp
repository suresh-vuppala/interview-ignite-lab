// ============================================================
// Maximal Rectangle
// ============================================================

#include <vector>
#include <stack>
using namespace std;

class Solution1 {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int R = matrix.size(), C = matrix[0].size(), maxArea = 0;
        for (int r1 = 0; r1 < R; r1++) {
            vector<int> minH(C, R);
            for (int r2 = r1; r2 < R; r2++) {
                for (int c = 0; c < C; c++)
                    if (matrix[r2][c] == '0') minH[c] = 0;
                int w = 0;
                for (int c = 0; c < C; c++) {
                    if (minH[c] > 0) { w++; maxArea = max(maxArea, w * (r2-r1+1)); }
                    else w = 0;
                }
            }
        }
        return maxArea;
    }
};

class Solution2 {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int C = matrix[0].size(), maxArea = 0;
        vector<int> heights(C, 0);

        for (auto& row : matrix) {
            // Build histogram heights for this row
            for (int j = 0; j < C; j++)
                heights[j] = (row[j] == '1') ? heights[j] + 1 : 0;

            // Apply Largest Rectangle in Histogram
            maxArea = max(maxArea, largestRect(heights));
        }
        return maxArea;
    }

    int largestRect(vector<int>& h) {
        stack<int> st; st.push(-1);
        int maxA = 0;
        for (int i = 0; i <= (int)h.size(); i++) {
            int cur = (i == (int)h.size()) ? 0 : h[i];
            while (st.top() != -1 && cur <= h[st.top()]) {
                int height = h[st.top()]; st.pop();
                maxA = max(maxA, height * (i - st.top() - 1));
            }
            st.push(i);
        }
        return maxA;
    }
};
