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
#include <string>
#include <unordered_map>
using namespace std;

// Time: O(L) all operations | Space: O(N) nodes

struct RadixNode {
    unordered_map<char, RadixNode*> children;
    bool isEnd = false;
    string edgeLabel;
};

class CompressedTrie {
    RadixNode* root;
    
public:
    CompressedTrie() {
        root = new RadixNode();
    }
    
    void insert(string word) {
        RadixNode* node = root;
        int i = 0;
        
        while (i < word.size()) {
            char ch = word[i];
            if (!node->children[ch]) {
                RadixNode* newNode = new RadixNode();
                newNode->edgeLabel = word.substr(i);
                newNode->isEnd = true;
                node->children[ch] = newNode;
                return;
            }
            
            RadixNode* child = node->children[ch];
            string label = child->edgeLabel;
            int j = 0;
            
            while (j < label.size() && i < word.size() && label[j] == word[i]) {
                i++; j++;
            }
            
            if (j < label.size()) {
                // Split edge
                RadixNode* splitNode = new RadixNode();
                splitNode->edgeLabel = label.substr(0, j);
                splitNode->children[label[j]] = child;
                child->edgeLabel = label.substr(j);
                node->children[ch] = splitNode;
                
                if (i < word.size()) {
                    RadixNode* newNode = new RadixNode();
                    newNode->edgeLabel = word.substr(i);
                    newNode->isEnd = true;
                    splitNode->children[word[i]] = newNode;
                } else {
                    splitNode->isEnd = true;
                }
                return;
            }
            node = child;
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        RadixNode* node = root;
        int i = 0;
        
        while (i < word.size()) {
            char ch = word[i];
            if (!node->children[ch]) return false;
            
            RadixNode* child = node->children[ch];
            string label = child->edgeLabel;
            
            for (char c : label) {
                if (i >= word.size() || word[i] != c) return false;
                i++;
            }
            node = child;
        }
        return node->isEnd;
    }
};
