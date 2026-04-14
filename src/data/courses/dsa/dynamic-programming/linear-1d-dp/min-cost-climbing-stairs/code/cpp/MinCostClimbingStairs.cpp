#include <vector>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: Recursion — O(2^N) Time, O(N) Space
// ============================================================
class Solution1 {
public:
    int solve(vector<int>& cost, int i) {
        if (i <= 1) return cost[i];
        return cost[i] + min(solve(cost, i-1), solve(cost, i-2));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        return min(solve(cost, n-1), solve(cost, n-2));
    }
};

// ============================================================
// Solution 2: DP — Bottom-up with two variables — O(N) Time, O(1) Space
// ============================================================
class Solution2 {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int prev2 = cost[0], prev1 = cost[1];
        for (int i = 2; i < n; i++) {
            int curr = cost[i] + min(prev1, prev2);
            prev2 = prev1; prev1 = curr;
        }
        return min(prev1, prev2);
    }
};
