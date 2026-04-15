// ============================================================
// Solution 1: Standard Trie (one char per node)
// Time: O(L) per op | Space: O(N * L * 26) — wastes nodes
// ============================================================
#include <string>
using namespace std;

class Solution1 {
    struct Node { Node* ch[26] = {}; bool end = false; };
    Node* root = new Node();
public:
    void insert(string word) {
        Node* n = root;
        for (char c : word) {
            if (!n->ch[c-'a']) n->ch[c-'a'] = new Node();
            n = n->ch[c-'a'];
        }
        n->end = true;
        // Standard trie: one node per character — wastes space on long chains
    }
    bool search(string word) {
        Node* n = root;
        for (char c : word) { if (!n->ch[c-'a']) return false; n = n->ch[c-'a']; }
        return n->end;
    }
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

class Solution2 {
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
