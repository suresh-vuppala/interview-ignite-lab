#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    // ==================== SOLUTION 1: RECURSIVE (BRUTE FORCE) ====================
    // Time: O(4^N) | Space: O(N)
    int cherryPickupRecursive(vector<vector<int>>& grid) {
        return max(0, solve(grid, 0, 0, 0));
    }
    
private:
    int solve(vector<vector<int>>& grid, int r1, int c1, int r2) {
        int n = grid.size();
        int c2 = r1 + c1 - r2;
        if (r1 >= n || c1 >= n || r2 >= n || c2 >= n || grid[r1][c1] == -1 || grid[r2][c2] == -1) {
            return INT_MIN;
        }
        if (r1 == n-1 && c1 == n-1) return grid[r1][c1];
        int cherries = grid[r1][c1];
        if (r1 != r2) cherries += grid[r2][c2];
        cherries += max({solve(grid, r1+1, c1, r2+1), solve(grid, r1, c1+1, r2+1),
                        solve(grid, r1+1, c1, r2), solve(grid, r1, c1+1, r2)});
        return cherries;
    }
    
public:
    // ==================== SOLUTION 2: MEMOIZATION (TOP-DOWN DP) ====================
    // Time: O(N³) | Space: O(N³)
    int cherryPickupMemo(vector<vector<int>>& grid) {
        unordered_map<string, int> memo;
        return max(0, solveMemo(grid, 0, 0, 0, memo));
    }
    
private:
    int solveMemo(vector<vector<int>>& grid, int r1, int c1, int r2, unordered_map<string, int>& memo) {
        int n = grid.size();
        int c2 = r1 + c1 - r2;
        if (r1 >= n || c1 >= n || r2 >= n || c2 >= n || grid[r1][c1] == -1 || grid[r2][c2] == -1) {
            return INT_MIN;
        }
        if (r1 == n-1 && c1 == n-1) return grid[r1][c1];
        string key = to_string(r1) + "," + to_string(c1) + "," + to_string(r2);
        if (memo.count(key)) return memo[key];
        int cherries = grid[r1][c1];
        if (r1 != r2) cherries += grid[r2][c2];
        cherries += max({solveMemo(grid, r1+1, c1, r2+1, memo), solveMemo(grid, r1, c1+1, r2+1, memo),
                        solveMemo(grid, r1+1, c1, r2, memo), solveMemo(grid, r1, c1+1, r2, memo)});
        memo[key] = cherries;
        return cherries;
    }
    
public:
    // ==================== SOLUTION 3: TABULATION (BOTTOM-UP DP) ====================
    // Time: O(N³) | Space: O(N³)
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, INT_MIN)));
        dp[0][0][0] = grid[0][0];
        for (int r1 = 0; r1 < n; r1++) {
            for (int c1 = 0; c1 < n; c1++) {
                for (int r2 = 0; r2 < n; r2++) {
                    int c2 = r1 + c1 - r2;
                    if (c2 < 0 || c2 >= n || grid[r1][c1] == -1 || grid[r2][c2] == -1) continue;
                    int cherries = grid[r1][c1];
                    if (r1 != r2) cherries += grid[r2][c2];
                    vector<pair<int,int>> prev = {{r1-1, c1}, {r1, c1-1}};
                    for (auto [pr1, pc1] : prev) {
                        for (int pr2 : {r2-1, r2}) {
                            if (pr1 >= 0 && pc1 >= 0 && pr2 >= 0) {
                                dp[r1][c1][r2] = max(dp[r1][c1][r2], dp[pr1][pc1][pr2] + cherries);
                            }
                        }
                    }
                }
            }
        }
        return max(0, dp[n-1][n-1][n-1]);
    }
};
