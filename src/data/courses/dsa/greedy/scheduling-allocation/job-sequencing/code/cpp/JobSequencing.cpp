#include <vector>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: Try all permutations — O(N!)
// ============================================================
class Solution1 {
public:
    // Brute: try scheduling each job, pick max profit arrangement
    int jobSequencing(vector<vector<int>>& jobs) {
        // Sort by profit descending, try to fit each greedily (this IS greedy)
        sort(jobs.begin(), jobs.end(), [](auto& a, auto& b){ return a[1] > b[1]; });
        int maxDeadline = 0;
        for (auto& j : jobs) maxDeadline = max(maxDeadline, j[0]);
        vector<bool> slot(maxDeadline + 1, false);
        int profit = 0;
        for (auto& j : jobs) {
            for (int t = j[0]; t >= 1; t--) {
                if (!slot[t]) { slot[t] = true; profit += j[1]; break; }
            }
        }
        return profit; // O(N * maxDeadline)
    }
};

// ============================================================
// Solution 2: Sort by profit + DSU for fast slot finding — O(N log N)
// ============================================================
class Solution2 {
    vector<int> parent;
    int find(int x) { return parent[x] == x ? x : parent[x] = find(parent[x]); }
public:
    int jobSequencing(vector<vector<int>>& jobs) {
        sort(jobs.begin(), jobs.end(), [](auto& a, auto& b){ return a[1] > b[1]; });
        int maxD = 0;
        for (auto& j : jobs) maxD = max(maxD, j[0]);
        parent.resize(maxD + 1);
        for (int i = 0; i <= maxD; i++) parent[i] = i;
        int profit = 0;
        for (auto& j : jobs) {
            int slot = find(j[0]);
            if (slot > 0) { profit += j[1]; parent[slot] = slot - 1; }
        }
        return profit;
    }
};
