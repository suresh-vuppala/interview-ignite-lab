// ============================================================
// Solution 1: Brute Force Recursion — try all splits
// Time: O(2^N) | Space: O(N)
// ============================================================
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution1 {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        return canBreak(s, 0, dict);
    }
    bool canBreak(string& s, int start, unordered_set<string>& dict) {
        if (start == (int)s.size()) return true;
        for (int end = start + 1; end <= (int)s.size(); end++)
            if (dict.count(s.substr(start, end - start)) && canBreak(s, end, dict))
                return true;
        return false;
    }
};

// ============================================================
// Solution 2: Trie + DP — O(N × L)
// Time: O(N × L) where L = max word length | Space: O(N + D×L)
// ============================================================
class Solution2 {
    struct TrieNode { TrieNode* ch[26] = {}; bool isEnd = false; };
    TrieNode* root = new TrieNode();
    
    void insert(string& word) {
        TrieNode* n = root;
        for (char c : word) {
            if (!n->ch[c-'a']) n->ch[c-'a'] = new TrieNode();
            n = n->ch[c-'a'];
        }
        n->isEnd = true;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        for (auto& w : wordDict) insert(w);
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 0; i < n; i++) {
            if (!dp[i]) continue;
            TrieNode* node = root;
            for (int j = i; j < n; j++) {
                if (!node->ch[s[j]-'a']) break; // No more words match
                node = node->ch[s[j]-'a'];
                if (node->isEnd) dp[j + 1] = true; // Word found!
            }
        }
        return dp[n];
    }
};
