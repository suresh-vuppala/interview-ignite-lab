// ============================================================
// Online Stock Span
// ============================================================

#include <stack>
using namespace std;

// ============================================================
// Solution 1: Brute Force — Store All, Scan Back
// Time: O(N) per call | Space: O(N)
// ============================================================
class StockSpanner1 {
    vector<int> prices;
public:
    int next(int price) {
        prices.push_back(price);
        int span = 1;
        int i = prices.size() - 2;
        while (i >= 0 && prices[i] <= price) {
            span++;
            i--;
        }
        return span;
    }
};

// ============================================================
// Solution 2: Monotonic Decreasing Stack (Optimal)
// Time: O(1) amortized | Space: O(N)
// ============================================================
class StockSpanner2 {
    stack<pair<int, int>> st; // (price, index)
    int day = 0;

public:
    int next(int price) {
        // Pop all prices ≤ current (today spans over them)
        while (!st.empty() && st.top().first <= price) {
            st.pop();
        }

        // Span = distance to previous greater element
        int span = st.empty() ? day + 1 : day - st.top().second;

        st.push({price, day});
        day++;

        return span;
    }
};
