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
using namespace std;

class MaximumXorTwoNumbers {
    struct TrieNode {
        TrieNode* children[2] = {}; // 0 and 1 for binary
    };
    
    TrieNode* root = new TrieNode();
    
    void insert(int num) {
        TrieNode* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->children[bit]) {
                node->children[bit] = new TrieNode();
            }
            node = node->children[bit];
        }
    }
    
    int getMaxXor(int num) {
        TrieNode* node = root;
        int xor_val = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int opposite = 1 - bit; // Choose opposite for max XOR
            if (node->children[opposite]) {
                xor_val |= (1 << i); // Set bit in result
                node = node->children[opposite];
            } else {
                node = node->children[bit];
            }
        }
        return xor_val;
    }
    
public:
    int findMaximumXOR(vector<int>& nums) {
        // Insert all numbers into trie
        for (int num : nums) insert(num);
        
        // Find max XOR for each number
        int maxXor = 0;
        for (int num : nums) {
            maxXor = max(maxXor, getMaxXor(num));
        }
        return maxXor;
    }
};
