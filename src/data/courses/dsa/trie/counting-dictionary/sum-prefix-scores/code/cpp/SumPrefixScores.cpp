// ============================================================
// Solution 1: For each word, count prefix matches in all words
// Time: O(N² * L) | Space: O(1) extra
// ============================================================
#include <vector>
#include <string>
using namespace std;

class Solution1 {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        int n = words.size();
        vector<int> scores(n, 0);
        for (int i = 0; i < n; i++) {
            for (int len = 1; len <= (int)words[i].size(); len++) {
                string prefix = words[i].substr(0, len);
                for (int j = 0; j < n; j++)
                    if (words[j].size() >= prefix.size() && words[j].substr(0, len) == prefix)
                        scores[i]++;
            }
        }
        return scores;  // O(N²*L) — check each prefix against all words
    }
};

// ============================================================
// Solution 2: Trie with prefix count at each node (Optimal)
// Time: O(N * L) | Space: O(N * L)
// ============================================================
struct TrieNode {
    TrieNode* children[26] = {};
    int count = 0;  // How many words pass through this node
};

class Solution2 {
    TrieNode* root = new TrieNode();
public:
    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children[c - 'a'])
                node->children[c - 'a'] = new TrieNode();
            node = node->children[c - 'a'];
            node->count++;  // Increment prefix count
        }
    }

    int getPrefixScore(const string& word) {
        TrieNode* node = root;
        int score = 0;
        for (char c : word) {
            node = node->children[c - 'a'];
            score += node->count;  // Add count at each prefix node
        }
        return score;
    }

    vector<int> sumPrefixScores(vector<string>& words) {
        for (auto& w : words) insert(w);
        vector<int> result;
        for (auto& w : words) result.push_back(getPrefixScore(w));
        return result;
    }
};
