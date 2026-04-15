#include <vector>
#include <functional>
using namespace std;
// ============================================================
// Solution 1: Linear scan — O(N) Time
// ============================================================
class Solution1 {
public:
    int findFirstTrue(vector<bool>& arr) {
        for (int i = 0; i < (int)arr.size(); i++)
            if (arr[i]) return i;
        return -1;
    }
};

// ============================================================
// Solution 2: Binary search on monotonic boolean — O(log N) Time
// ============================================================
class Solution2 {
public:
    int findFirstTrue(vector<bool>& arr) {
        int lo = 0, hi = arr.size() - 1, ans = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (arr[mid]) { ans = mid; hi = mid - 1; } // Go left for earlier true
            else lo = mid + 1;
        }
        return ans;
    }
};
