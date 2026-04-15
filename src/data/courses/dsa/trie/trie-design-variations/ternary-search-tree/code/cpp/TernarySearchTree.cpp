// ============================================================
// Solution 1: Standard 26-children Trie
// Time: O(L) per op | Space: O(N * L * 26) — sparse waste
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
        // 26 children per node — wastes memory for sparse alphabets
        // TST uses only 3 pointers per node
    }
};

// ============================================================
// Solution 2: Optimal (Trie-based)
// ============================================================
#include <string>
using namespace std;

// Time: O(L + log N) | Space: O(N)

struct TSTNode {
    char ch;
    TSTNode* left;
    TSTNode* middle;
    TSTNode* right;
    bool isEnd;
    
    TSTNode(char c) : ch(c), left(nullptr), middle(nullptr), right(nullptr), isEnd(false) {}
};

class Solution2 {
    TSTNode* root;
    
    TSTNode* insert(TSTNode* node, const string& word, int index) {
        char ch = word[index];
        if (!node) node = new TSTNode(ch);
        
        if (ch < node->ch) {
            node->left = insert(node->left, word, index);
        } else if (ch > node->ch) {
            node->right = insert(node->right, word, index);
        } else {
            if (index < word.size() - 1) {
                node->middle = insert(node->middle, word, index + 1);
            } else {
                node->isEnd = true;
            }
        }
        return node;
    }
    
    TSTNode* search(TSTNode* node, const string& word, int index) {
        if (!node) return nullptr;
        
        char ch = word[index];
        if (ch < node->ch) {
            return search(node->left, word, index);
        } else if (ch > node->ch) {
            return search(node->right, word, index);
        } else {
            if (index == word.size() - 1) return node;
            return search(node->middle, word, index + 1);
        }
    }
    
public:
    TernarySearchTree() : root(nullptr) {}
    
    void insert(string word) {
        root = insert(root, word, 0);
    }
    
    bool search(string word) {
        TSTNode* node = search(root, word, 0);
        return node && node->isEnd;
    }
};
