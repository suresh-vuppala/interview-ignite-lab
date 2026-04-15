// ============================================================
// Solution 1: Brute Force — All pairs with constraint check
// Time: O(N²) per query | Space: O(N)
// ============================================================
#include <vector>
#include <algorithm>
using namespace std;

class Solution1 {
public:
    int maxXorWithConstraint(vector<int>& nums, int x, int limit) {
        int maxXor = -1;
        for (int n : nums) {
            if (n <= limit)  // Only consider nums within constraint
                maxXor = max(maxXor, n ^ x);
        }
        return maxXor;  // O(N) per query, O(Q*N) total
    }
};

// ============================================================
// Solution 2: Optimal (Trie-based)
// ============================================================
#include <vector>
#include <algorithm>
using namespace std;

class Solution2 {
    struct TrieNode {
        TrieNode* children[2] = {};
    };
    
    void insert(TrieNode* root, int num) {
        TrieNode* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->children[bit]) node->children[bit] = new TrieNode();
            node = node->children[bit];
        }
    }
    
    int getMaxXor(TrieNode* root, int x, int m) {
        TrieNode* node = root;
        int xor_val = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (x >> i) & 1;
            int opposite = 1 - bit;
            if (node->children[opposite]) {
                xor_val |= (1 << i);
                node = node->children[opposite];
            } else if (node->children[bit]) {
                node = node->children[bit];
            } else {
                return -1;
            }
        }
        return xor_val <= m ? xor_val : -1;
    }
    
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> indexedQueries;
        for (int i = 0; i < queries.size(); i++) {
            indexedQueries.push_back({queries[i][0], queries[i][1], i});
        }
        sort(indexedQueries.begin(), indexedQueries.end(), 
             [](auto& a, auto& b) { return a[1] < b[1]; });
        
        vector<int> result(queries.size());
        TrieNode* root = new TrieNode();
        int idx = 0;
        
        for (auto& query : indexedQueries) {
            int x = query[0], m = query[1], qIdx = query[2];
            while (idx < nums.size() && nums[idx] <= m) {
                insert(root, nums[idx++]);
            }
            result[qIdx] = idx == 0 ? -1 : getMaxXor(root, x, m);
        }
        return result;
    }
};
