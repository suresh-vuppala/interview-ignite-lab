// ============================================================
// Solution 1: Sort + binary search per prefix
// Time: O(N log N + M * N * L) | Space: O(1) extra
// ============================================================
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution1 {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string word) {
        sort(products.begin(), products.end());
        vector<vector<string>> result;
        string prefix = "";
        for (char c : word) {
            prefix += c;
            vector<string> matches;
            for (auto& p : products) {  // Scan all products per keystroke!
                if (p.size() >= prefix.size() && p.substr(0, prefix.size()) == prefix)
                    matches.push_back(p);
                if (matches.size() == 3) break;
            }
            result.push_back(matches);
        }
        return result;
    }
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

class Solution2 {
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
