struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
#include <vector>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: Inorder to array, find swapped, fix — O(N) Space
// ============================================================
class Solution1 {
    void inorder(TreeNode* n, vector<TreeNode*>& v) { if(!n)return; inorder(n->left,v); v.push_back(n); inorder(n->right,v); }
public:
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> nodes; inorder(root, nodes);
        TreeNode *first = nullptr, *second = nullptr;
        for (int i = 0; i < (int)nodes.size()-1; i++) {
            if (nodes[i]->val > nodes[i+1]->val) {
                if (!first) first = nodes[i];
                second = nodes[i+1];
            }
        }
        if (first && second) swap(first->val, second->val);
    }
};

// ============================================================
// Solution 2: Morris traversal — O(N) Time, O(1) Space!
// ============================================================
class Solution2 {
public:
    void recoverTree(TreeNode* root) {
        TreeNode *first=nullptr,*second=nullptr,*prev=nullptr,*cur=root;
        while (cur) {
            if (!cur->left) {
                if (prev && prev->val > cur->val) { if(!first)first=prev; second=cur; }
                prev = cur; cur = cur->right;
            } else {
                TreeNode* pred = cur->left;
                while (pred->right && pred->right != cur) pred = pred->right;
                if (!pred->right) { pred->right = cur; cur = cur->left; }
                else {
                    pred->right = nullptr;
                    if (prev && prev->val > cur->val) { if(!first)first=prev; second=cur; }
                    prev = cur; cur = cur->right;
                }
            }
        }
        if (first && second) swap(first->val, second->val);
    }
};
