// ============================================================
// Solution 1: HashSet — generate all substrings, store in set
// Time: O(N³) | Space: O(N²)
// ============================================================
#include <string>
#include <unordered_set>
using namespace std;

class Solution1 {
public:
    int countDistinct(string s) {
        unordered_set<string> substrings;
        int n = s.size();
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j <= n; j++)
                substrings.insert(s.substr(i, j - i)); // O(N) per insert
        return substrings.size(); // +1 for empty string if needed
    }
};

// ============================================================
// Solution 2: Suffix Trie — insert all suffixes, count nodes
// Time: O(N²) | Space: O(N²)
// ============================================================
class Solution2 {
    struct TrieNode { TrieNode* ch[26] = {}; };
public:
    int countDistinct(string s) {
        TrieNode* root = new TrieNode();
        int count = 0, n = s.size();
        // Insert each suffix into trie
        for (int i = 0; i < n; i++) {
            TrieNode* node = root;
            for (int j = i; j < n; j++) {
                int idx = s[j] - 'a';
                if (!node->ch[idx]) {
                    node->ch[idx] = new TrieNode();
                    count++; // New node = new distinct substring
                }
                node = node->ch[idx];
            }
        }
        return count; // +1 for empty string if needed
    }
};
