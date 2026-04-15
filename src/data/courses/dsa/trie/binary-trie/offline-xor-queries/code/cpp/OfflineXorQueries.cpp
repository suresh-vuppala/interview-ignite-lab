// ============================================================
// Solution 1: Brute Force — Process each query by scanning all valid nums
// Time: O(Q * N) | Space: O(N)
// ============================================================
#include <vector>
#include <algorithm>
using namespace std;

class Solution1 {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans(queries.size());
        for (int i = 0; i < (int)queries.size(); i++) {
            int xi = queries[i][0], mi = queries[i][1];
            ans[i] = -1;
            for (int n : nums) {
                if (n <= mi)
                    ans[i] = max(ans[i], n ^ xi);
            }
        }
        return ans;  // O(Q*N) — no sorting, no trie
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
    
    int getMaxXor(TrieNode* root, int num) {
        TrieNode* node = root;
        int xor_val = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int opposite = 1 - bit;
            if (node->children[opposite]) {
                xor_val |= (1 << i);
                node = node->children[opposite];
            } else {
                node = node->children[bit];
            }
        }
        return xor_val;
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
            result[qIdx] = idx == 0 ? -1 : getMaxXor(root, x);
        }
        return result;
    }
};
