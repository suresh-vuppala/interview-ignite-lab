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

class TernarySearchTree {
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
