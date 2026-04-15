#include <vector>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: Check every possible distance — O(range * N)
// ============================================================
class Solution1 {
    bool canPlace(vector<int>& pos, int m, int minDist) {
        int count = 1, last = pos[0];
        for (int i = 1; i < (int)pos.size(); i++)
            if (pos[i] - last >= minDist) { count++; last = pos[i]; }
        return count >= m;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        for (int d = position.back() - position[0]; d >= 1; d--)
            if (canPlace(position, m, d)) return d;
        return 1;
    }
};

// ============================================================
// Solution 2: Binary Search on distance — O(N log range)
// ============================================================
class Solution2 {
    bool canPlace(vector<int>& pos, int m, int minDist) {
        int count = 1, last = pos[0];
        for (int i = 1; i < (int)pos.size(); i++)
            if (pos[i] - last >= minDist) { count++; last = pos[i]; }
        return count >= m;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int lo = 1, hi = position.back() - position[0];
        while (lo < hi) { int mid = lo + (hi - lo + 1) / 2; if (canPlace(position, m, mid)) lo = mid; else hi = mid - 1; }
        return lo;
    }
};
