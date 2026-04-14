// ============================================================
// Solution 1: Vertical Scanning — Compare char by char
// Time: O(N × L) | Space: O(1)
// ============================================================
#include <vector>
#include <string>
using namespace std;

class Solution1 {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        // Compare character by character across all strings
        for (int i = 0; i < (int)strs[0].size(); i++) {
            char c = strs[0][i];
            for (int j = 1; j < (int)strs.size(); j++) {
                if (i >= (int)strs[j].size() || strs[j][i] != c)
                    return strs[0].substr(0, i);
            }
        }
        return strs[0];
    }
};

// ============================================================
// Solution 2: Trie — Insert all, walk single-child path
// Time: O(N × L) | Space: O(N × L)
// ============================================================
class Solution2 {
    struct TrieNode {
        TrieNode* children[26] = {};
        int childCount = 0;
        bool isEnd = false;
    };
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        TrieNode* root = new TrieNode();
        // Insert all strings
        for (auto& s : strs) {
            TrieNode* node = root;
            for (char c : s) {
                int idx = c - 'a';
                if (!node->children[idx]) {
                    node->children[idx] = new TrieNode();
                    node->childCount++;
                }
                node = node->children[idx];
            }
            node->isEnd = true;
        }
        // Walk single-child path
        string prefix;
        TrieNode* node = root;
        while (node->childCount == 1 && !node->isEnd) {
            for (int i = 0; i < 26; i++) {
                if (node->children[i]) {
                    prefix += ('a' + i);
                    node = node->children[i];
                    break;
                }
            }
        }
        return prefix;
    }
};
