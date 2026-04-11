// ============================================================
// Daily Temperatures
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
    vector<int> dailyTemperatures(vector<int>& temps) {
        int n = temps.size();
        vector<int> result(n, 0);
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (temps[j] > temps[i]) { result[i] = j - i; break; }
        return result;
    }
};

// ============================================================
// Solution 2: Monotonic Decreasing Stack (Optimal)
// Time: O(N) | Space: O(N)
// ============================================================
class Solution2 {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        int n = temps.size();
        vector<int> result(n, 0);
        stack<int> st; // Indices — decreasing temp order

        for (int i = 0; i < n; i++) {
            // Current temp resolves all colder days on stack
            while (!st.empty() && temps[i] > temps[st.top()]) {
                int idx = st.top();
                st.pop();
                result[idx] = i - idx; // Days to wait
            }
            st.push(i);
        }

        return result;
    }
};
