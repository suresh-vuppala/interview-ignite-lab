#include <vector>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: Try all distances — O((max-min) * N)
// ============================================================
class Solution1 {
    bool canPlace(vector<int>& stalls, int cows, int minDist) {
        int count = 1, lastPos = stalls[0];
        for (int i = 1; i < (int)stalls.size(); i++) {
            if (stalls[i] - lastPos >= minDist) { count++; lastPos = stalls[i]; }
        }
        return count >= cows;
    }
public:
    int maxMinDistance(vector<int>& stalls, int cows) {
        sort(stalls.begin(), stalls.end());
        int maxDist = stalls.back() - stalls[0];
        for (int d = maxDist; d >= 1; d--) // Linear scan from max down
            if (canPlace(stalls, cows, d)) return d;
        return 1;
    }
};

// ============================================================
// Solution 2: Binary Search on distance — O(N log(max-min))
// ============================================================
class Solution2 {
    bool canPlace(vector<int>& stalls, int cows, int minDist) {
        int count = 1, lastPos = stalls[0];
        for (int i = 1; i < (int)stalls.size(); i++)
            if (stalls[i] - lastPos >= minDist) { count++; lastPos = stalls[i]; }
        return count >= cows;
    }
public:
    int maxMinDistance(vector<int>& stalls, int cows) {
        sort(stalls.begin(), stalls.end());
        int lo = 1, hi = stalls.back() - stalls[0];
        while (lo < hi) { int mid = lo + (hi - lo + 1) / 2; if (canPlace(stalls, cows, mid)) lo = mid; else hi = mid - 1; }
        return lo;
    }
};
