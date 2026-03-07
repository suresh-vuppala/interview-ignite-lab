#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    // ==================== SOLUTION 1: RECURSIVE (BRUTE FORCE) ====================
    // Time: O(3^(M+N)) | Space: O(M+N)
    int minDistanceRecursive(string word1, string word2) {
        return solve(word1, word2, word1.length(), word2.length());
    }
    
private:
    int solve(string& word1, string& word2, int i, int j) {
        if (i == 0) return j;
        if (j == 0) return i;
        if (word1[i-1] == word2[j-1]) {
            return solve(word1, word2, i-1, j-1);
        }
        return 1 + min({solve(word1, word2, i-1, j), 
                       solve(word1, word2, i, j-1), 
                       solve(word1, word2, i-1, j-1)});
    }
    
public:
    // ==================== SOLUTION 2: MEMOIZATION (TOP-DOWN DP) ====================
    // Time: O(M×N) | Space: O(M×N)
    int minDistanceMemo(string word1, string word2) {
        unordered_map<string, int> memo;
        return solveMemo(word1, word2, word1.length(), word2.length(), memo);
    }
    
private:
    int solveMemo(string& word1, string& word2, int i, int j, unordered_map<string, int>& memo) {
        if (i == 0) return j;
        if (j == 0) return i;
        string key = to_string(i) + "," + to_string(j);
        if (memo.count(key)) return memo[key];
        if (word1[i-1] == word2[j-1]) {
            memo[key] = solveMemo(word1, word2, i-1, j-1, memo);
        } else {
            memo[key] = 1 + min({solveMemo(word1, word2, i-1, j, memo),
                                solveMemo(word1, word2, i, j-1, memo),
                                solveMemo(word1, word2, i-1, j-1, memo)});
        }
        return memo[key];
    }
    
public:
    // ==================== SOLUTION 3: TABULATION (BOTTOM-UP DP) ====================
    // Time: O(M×N) | Space: O(M×N)
    int minDistanceTab(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i <= m; i++) dp[i][0] = i;
        for (int j = 0; j <= n; j++) dp[0][j] = j;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                }
            }
        }
        return dp[m][n];
    }
    
    // ==================== SOLUTION 4: SPACE OPTIMIZED ====================
    // Time: O(M×N) | Space: O(N)
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        vector<int> prev(n + 1);
        for (int j = 0; j <= n; j++) prev[j] = j;
        for (int i = 1; i <= m; i++) {
            vector<int> curr(n + 1);
            curr[0] = i;
            for (int j = 1; j <= n; j++) {
                if (word1[i-1] == word2[j-1]) {
                    curr[j] = prev[j-1];
                } else {
                    curr[j] = 1 + min({prev[j], curr[j-1], prev[j-1]});
                }
            }
            prev = curr;
        }
        return prev[n];
    }
};
