#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    // ==================== SOLUTION 1: RECURSIVE (BRUTE FORCE) ====================
    // Time: O(2^N) | Space: O(N)
    bool wordBreakRecursive(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        return solve(s, 0, wordSet);
    }
    
private:
    bool solve(string& s, int i, unordered_set<string>& wordSet) {
        if (i == s.length()) return true;
        for (int j = i + 1; j <= s.length(); j++) {
            if (wordSet.count(s.substr(i, j - i)) && solve(s, j, wordSet)) {
                return true;
            }
        }
        return false;
    }
    
public:
    // ==================== SOLUTION 2: MEMOIZATION (TOP-DOWN DP) ====================
    // Time: O(N²) | Space: O(N)
    bool wordBreakMemo(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        unordered_map<int, bool> memo;
        return solveMemo(s, 0, wordSet, memo);
    }
    
private:
    bool solveMemo(string& s, int i, unordered_set<string>& wordSet, unordered_map<int, bool>& memo) {
        if (i == s.length()) return true;
        if (memo.count(i)) return memo[i];
        for (int j = i + 1; j <= s.length(); j++) {
            if (wordSet.count(s.substr(i, j - i)) && solveMemo(s, j, wordSet, memo)) {
                memo[i] = true;
                return true;
            }
        }
        memo[i] = false;
        return false;
    }
    
public:
    // ==================== SOLUTION 3: TABULATION (BOTTOM-UP DP) ====================
    // Time: O(N²) | Space: O(N)
    bool wordBreakTab(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        int n = s.length();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && wordSet.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
    
    // ==================== SOLUTION 4: SPACE OPTIMIZED (BFS) ====================
    // Time: O(N²) | Space: O(N)
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        unordered_set<int> visited;
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int start = q.front();
            q.pop();
            if (visited.count(start)) continue;
            visited.insert(start);
            for (int end = start + 1; end <= s.length(); end++) {
                if (wordSet.count(s.substr(start, end - start))) {
                    if (end == s.length()) return true;
                    q.push(end);
                }
            }
        }
        return false;
    }
};
