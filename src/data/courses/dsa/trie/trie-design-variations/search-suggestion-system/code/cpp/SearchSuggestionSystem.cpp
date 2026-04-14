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
#include <algorithm>
using namespace std;

// Time: O(N*L*log N) build, O(L) query | Space: O(N*L)

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    vector<string> suggestions;
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        TrieNode* root = new TrieNode();
        
        // Build trie with top 3 suggestions
        for (const string& product : products) {
            TrieNode* node = root;
            for (char ch : product) {
                if (!node->children[ch]) {
                    node->children[ch] = new TrieNode();
                }
                node = node->children[ch];
                if (node->suggestions.size() < 3) {
                    node->suggestions.push_back(product);
                }
            }
        }
        
        // Query for each prefix
        vector<vector<string>> result;
        TrieNode* node = root;
        for (char ch : searchWord) {
            if (node && node->children[ch]) {
                node = node->children[ch];
                result.push_back(node->suggestions);
            } else {
                node = nullptr;
                result.push_back({});
            }
        }
        return result;
    }
};
