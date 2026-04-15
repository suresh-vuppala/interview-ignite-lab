#include <vector>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: Try all possible fractions — impractical (continuous)
// ============================================================
class Solution1 {
public:
    double fractionalKnapsack(int W, vector<vector<int>>& items) {
        // For fractional: brute force doesn't make sense (infinite fractions)
        // Simple O(N²): pick best ratio each step without sorting
        int n = items.size();
        vector<bool> used(n, false);
        double totalVal = 0;
        int remW = W;
        for (int step = 0; step < n && remW > 0; step++) {
            int best = -1; double bestRatio = -1;
            for (int i = 0; i < n; i++) {
                if (used[i]) continue;
                double ratio = (double)items[i][1] / items[i][0];
                if (ratio > bestRatio) { bestRatio = ratio; best = i; }
            }
            if (best == -1) break;
            used[best] = true;
            int take = min(remW, items[best][0]);
            totalVal += take * bestRatio;
            remW -= take;
        }
        return totalVal; // O(N²) — no sorting
    }
};

// ============================================================
// Solution 2: Greedy — sort by value/weight ratio — O(N log N)
// ============================================================
class Solution2 {
public:
    double fractionalKnapsack(int W, vector<vector<int>>& items) {
        sort(items.begin(), items.end(), [](auto& a, auto& b){
            return (double)a[1]/a[0] > (double)b[1]/b[0]; // Descending ratio
        });
        double totalVal = 0;
        for (auto& item : items) {
            if (W >= item[0]) { totalVal += item[1]; W -= item[0]; }
            else { totalVal += (double)W / item[0] * item[1]; break; }
        }
        return totalVal;
    }
};
