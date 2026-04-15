#include <vector>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: Brute Force — try all C(N,K) placements — O(C(N,K) * N)
// ============================================================
class Solution1 {
    int minDist(vector<int>& pos, vector<int>& chosen) {
        int mn = INT_MAX;
        for (int i = 1; i < (int)chosen.size(); i++) mn = min(mn, pos[chosen[i]] - pos[chosen[i-1]]);
        return mn;
    }
    int best = 0;
    void solve(vector<int>& pos, int k, int start, vector<int>& chosen) {
        if ((int)chosen.size() == k) { best = max(best, minDist(pos, chosen)); return; }
        for (int i = start; i < (int)pos.size(); i++) { chosen.push_back(i); solve(pos, k, i+1, chosen); chosen.pop_back(); }
    }
public:
    int maxMinDistance(vector<int>& positions, int k) {
        sort(positions.begin(), positions.end());
        best = 0; vector<int> chosen; solve(positions, k, 0, chosen); return best;
    }
};

// ============================================================
// Solution 2: Binary Search on distance — O(N log range)
// ============================================================
class Solution2 {
    bool canPlace(vector<int>& pos, int k, int minDist) {
        int count = 1, last = pos[0];
        for (int i = 1; i < (int)pos.size(); i++)
            if (pos[i] - last >= minDist) { count++; last = pos[i]; }
        return count >= k;
    }
public:
    int maxMinDistance(vector<int>& positions, int k) {
        sort(positions.begin(), positions.end());
        int lo = 1, hi = positions.back() - positions[0];
        while (lo < hi) { int mid = lo + (hi - lo + 1) / 2; if (canPlace(positions, k, mid)) lo = mid; else hi = mid - 1; }
        return lo;
    }
};
