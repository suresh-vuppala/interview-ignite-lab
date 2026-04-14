struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
using namespace std;
// ============================================================
// Solution 1: Inorder to sorted array, binary search — O(N) Space
// ============================================================
#include <vector>
class Solution1 {
    void inorder(TreeNode* n, vector<int>& v) { if(!n)return; inorder(n->left,v); v.push_back(n->val); inorder(n->right,v); }
public:
    int floor(TreeNode* root, int key) {
        vector<int> sorted; inorder(root, sorted);
        int res = -1;
        for (int x : sorted) if (x <= key) res = x;
        return res;
    }
    int ceil(TreeNode* root, int key) {
        vector<int> sorted; inorder(root, sorted);
        for (int x : sorted) if (x >= key) return x;
        return -1;
    }
};

// ============================================================
// Solution 2: BST property — single path O(H) Time, O(1) Space
// ============================================================
class Solution2 {
public:
    int floor(TreeNode* root, int key) {
        int res = -1;
        while (root) {
            if (root->val == key) return key;
            if (root->val < key) { res = root->val; root = root->right; }
            else root = root->left;
        }
        return res;
    }
    int ceil(TreeNode* root, int key) {
        int res = -1;
        while (root) {
            if (root->val == key) return key;
            if (root->val > key) { res = root->val; root = root->left; }
            else root = root->right;
        }
        return res;
    }
};
