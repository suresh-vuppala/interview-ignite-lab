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
using namespace std;

class PrefixScore {
    struct TrieNode {
        TrieNode* children[26] = {};
        int prefixCount = 0; // Count of words passing through
    };
    
    TrieNode* root = new TrieNode();
    
    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx]) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
            node->prefixCount++; // Increment count
        }
    }
    
    int getScore(string word) {
        TrieNode* node = root;
        int score = 0;
        
        for (char c : word) {
            int idx = c - 'a';
            node = node->children[idx];
            score += node->prefixCount; // Add prefix count
        }
        return score;
    }
    
public:
    int sumPrefixScores(vector<string>& words) {
        // Build trie with prefix counts
        for (string& word : words) {
            insert(word);
        }
        
        // Calculate sum of scores
        int totalScore = 0;
        for (string& word : words) {
            totalScore += getScore(word);
        }
        return totalScore;
    }
};
