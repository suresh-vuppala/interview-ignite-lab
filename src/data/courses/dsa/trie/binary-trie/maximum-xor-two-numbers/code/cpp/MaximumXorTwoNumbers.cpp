// ============================================================
// Solution 1: Check all pairs — O(N²)
// ============================================================
#include <vector>
#include <algorithm>
using namespace std;

class Solution1 {
public:
    int findMaximumXOR(vector<int>& nums) {
        int maxXor = 0;
        for (int i = 0; i < (int)nums.size(); i++)
            for (int j = i + 1; j < (int)nums.size(); j++)
                maxXor = max(maxXor, nums[i] ^ nums[j]);
        return maxXor;
    }
};

// ============================================================
// Solution 2: Binary Trie — O(N × 32) = O(N)
// ============================================================
class Solution2 {
    struct TrieNode { TrieNode* ch[2] = {}; };
    TrieNode* root = new TrieNode();
    
    void insert(int num) {
        TrieNode* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->ch[bit]) node->ch[bit] = new TrieNode();
            node = node->ch[bit];
        }
    }
    
    int getMaxXor(int num) {
        TrieNode* node = root;
        int xorVal = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int opposite = 1 - bit; // Want opposite bit for max XOR
            if (node->ch[opposite]) {
                xorVal |= (1 << i); // Set this bit in result
                node = node->ch[opposite];
            } else {
                node = node->ch[bit];
            }
        }
        return xorVal;
    }
public:
    int findMaximumXOR(vector<int>& nums) {
        for (int num : nums) insert(num);
        int maxXor = 0;
        for (int num : nums) maxXor = max(maxXor, getMaxXor(num));
        return maxXor;
    }
};
