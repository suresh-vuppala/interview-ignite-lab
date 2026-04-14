// ============================================================
// Solution 1: Brute Force
// ============================================================
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution1 {
public:
    // Brute force: use hash set / nested loops / direct comparison
    // See Solution 2 below for the optimal Trie-based approach
};

// ============================================================
// Solution 2: Optimal (Trie-based)
// ============================================================
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// Time: O(N*L²) | Space: O(N*L)

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    int index = -1;
    vector<int> palindromeSuffixes;
};

class Solution {
    bool isPalindrome(const string& word, int left, int right) {
        while (left < right) {
            if (word[left++] != word[right--]) return false;
        }
        return true;
    }
    
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        TrieNode* root = new TrieNode();
        
        // Build trie with reversed words
        for (int i = 0; i < words.size(); i++) {
            TrieNode* node = root;
            const string& word = words[i];
            for (int j = word.size() - 1; j >= 0; j--) {
                if (isPalindrome(word, 0, j)) {
                    node->palindromeSuffixes.push_back(i);
                }
                char ch = word[j];
                if (!node->children[ch]) {
                    node->children[ch] = new TrieNode();
                }
                node = node->children[ch];
            }
            node->index = i;
            node->palindromeSuffixes.push_back(i);
        }
        
        vector<vector<int>> result;
        for (int i = 0; i < words.size(); i++) {
            TrieNode* node = root;
            const string& word = words[i];
            for (int j = 0; j < word.size(); j++) {
                if (node->index >= 0 && node->index != i && isPalindrome(word, j, word.size() - 1)) {
                    result.push_back({i, node->index});
                }
                char ch = word[j];
                if (!node->children[ch]) break;
                node = node->children[ch];
            }
            if (node) {
                for (int idx : node->palindromeSuffixes) {
                    if (idx != i) {
                        result.push_back({i, idx});
                    }
                }
            }
        }
        return result;
    }
};
