#include <vector>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: Check each time point — O(N²)
// ============================================================
class Solution1 {
public:
    int minPlatforms(vector<int>& arr, vector<int>& dep) {
        int n = arr.size(), maxP = 0;
        for (int i = 0; i < n; i++) {
            int count = 1;
            for (int j = 0; j < n; j++) {
                if (i != j && arr[j] <= dep[i] && dep[j] >= arr[i]) count++;
            }
            maxP = max(maxP, count);
        }
        return maxP;
    }
};

// ============================================================
// Solution 2: Sort arrivals + departures, sweep — O(N log N)
// ============================================================
class Solution2 {
public:
    int minPlatforms(vector<int>& arr, vector<int>& dep) {
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        int plat = 0, maxP = 0, i = 0, j = 0, n = arr.size();
        while (i < n) {
            if (arr[i] <= dep[j]) { plat++; i++; }
            else { plat--; j++; }
            maxP = max(maxP, plat);
        }
        return maxP;
    }
};
