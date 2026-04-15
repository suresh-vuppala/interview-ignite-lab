#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// ============================================================
// Solution 1: Brute Force - Check All Pairs
// Time: O(N² × L) | Space: O(1)
// ============================================================
class Solution1 {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;
        int n = words.size();
        
        // Check every pair (i, j) where i < j
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // Skip if words[i] is longer than words[j]
                if (words[i].size() > words[j].size()) continue;
                
                // Check if words[i] is both prefix and suffix of words[j]
                if (isPrefixAndSuffix(words[i], words[j])) {
                    count++;
                }
            }
        }
        return count;
    }
    
private:
    bool isPrefixAndSuffix(const string& str1, const string& str2) {
        int len1 = str1.size();
        int len2 = str2.size();
        
        // Check prefix: first len1 characters of str2 match str1
        if (str2.substr(0, len1) != str1) return false;
        
        // Check suffix: last len1 characters of str2 match str1
        if (str2.substr(len2 - len1) != str1) return false;
        
        return true;
    }
};

// ============================================================
// Solution 2: Double Trie (Prefix Trie + Suffix Trie)
// Time: O(N × L²) | Space: O(N × L)
// ============================================================
struct TrieNode {
    unordered_map<char, TrieNode*> children;
    vector<int> wordIndices;  // Store indices of words ending here
};

class Solution2 {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        TrieNode* prefixRoot = new TrieNode();
        TrieNode* suffixRoot = new TrieNode();
        
        // Build prefix trie and suffix trie
        for (int i = 0; i < n; i++) {
            insertPrefix(prefixRoot, words[i], i);
            insertSuffix(suffixRoot, words[i], i);
        }
        
        int count = 0;
        // For each word, find matches
        for (int j = 0; j < n; j++) {
            vector<int> prefixMatches = searchPrefix(prefixRoot, words[j]);
            vector<int> suffixMatches = searchSuffix(suffixRoot, words[j]);
            
            // Find intersection (words that are both prefix and suffix)
            for (int i : prefixMatches) {
                if (i < j) {  // Only count pairs where i < j
                    for (int k : suffixMatches) {
                        if (i == k) {
                            count++;
                            break;
                        }
                    }
                }
            }
        }
        
        return count;
    }
    
private:
    void insertPrefix(TrieNode* root, const string& word, int index) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->wordIndices.push_back(index);
    }
    
    void insertSuffix(TrieNode* root, const string& word, int index) {
        TrieNode* node = root;
        // Insert reversed word
        for (int i = word.size() - 1; i >= 0; i--) {
            char c = word[i];
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->wordIndices.push_back(index);
    }
    
    vector<int> searchPrefix(TrieNode* root, const string& word) {
        vector<int> result;
        TrieNode* node = root;
        
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) break;
            node = node->children[c];
            // Collect all words ending at this node
            for (int idx : node->wordIndices) {
                result.push_back(idx);
            }
        }
        return result;
    }
    
    vector<int> searchSuffix(TrieNode* root, const string& word) {
        vector<int> result;
        TrieNode* node = root;
        
        // Search with reversed word
        for (int i = word.size() - 1; i >= 0; i--) {
            char c = word[i];
            if (node->children.find(c) == node->children.end()) break;
            node = node->children[c];
            // Collect all words ending at this node
            for (int idx : node->wordIndices) {
                result.push_back(idx);
            }
        }
        return result;
    }
};

// ============================================================
// Solution 3: Combined Trie (Optimal)
// Time: O(N × L²) | Space: O(N × L)
// ============================================================
struct PairTrieNode {
    unordered_map<int, PairTrieNode*> children;  // Key: (prefix_char << 8) | suffix_char
    int count = 0;  // Number of words ending at this node
};

class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        PairTrieNode* root = new PairTrieNode();
        int totalCount = 0;
        
        for (const string& word : words) {
            // Search first: count how many existing words are prefix-suffix of current word
            totalCount += search(root, word);
            
            // Then insert current word
            insert(root, word);
        }
        
        return totalCount;
    }
    
private:
    void insert(PairTrieNode* root, const string& word) {
        PairTrieNode* node = root;
        int len = word.size();
        
        // Traverse from both ends simultaneously
        for (int i = 0; i < len; i++) {
            int key = (word[i] << 8) | word[len - 1 - i];  // Combine prefix and suffix char
            
            if (node->children.find(key) == node->children.end()) {
                node->children[key] = new PairTrieNode();
            }
            node = node->children[key];
        }
        node->count++;
    }
    
    int search(PairTrieNode* root, const string& word) {
        PairTrieNode* node = root;
        int len = word.size();
        int count = 0;
        
        // Traverse from both ends simultaneously
        for (int i = 0; i < len; i++) {
            int key = (word[i] << 8) | word[len - 1 - i];
            
            if (node->children.find(key) == node->children.end()) {
                break;
            }
            node = node->children[key];
            // Add count of words that end at this position
            count += node->count;
        }
        
        return count;
    }
};
