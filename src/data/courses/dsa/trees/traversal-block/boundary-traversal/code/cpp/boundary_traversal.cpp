// ============================================================
// Boundary Traversal
// ============================================================
#include <vector>
using namespace std;
struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };

class Solution {
public:
    vector<int> boundaryTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> result;
        if (!isLeaf(root)) result.push_back(root->val);
        addLeftBoundary(root->left, result);
        addLeaves(root, result);
        addRightBoundary(root->right, result);
        return result;
    }
    bool isLeaf(TreeNode* n) { return n && !n->left && !n->right; }
    void addLeftBoundary(TreeNode* n, vector<int>& res) {
        while (n) {
            if (!isLeaf(n)) res.push_back(n->val);
            n = n->left ? n->left : n->right;
        }
    }
    void addLeaves(TreeNode* n, vector<int>& res) {
        if (!n) return;
        if (isLeaf(n)) { res.push_back(n->val); return; }
        addLeaves(n->left, res);
        addLeaves(n->right, res);
    }
    void addRightBoundary(TreeNode* n, vector<int>& res) {
        vector<int> temp;
        while (n) {
            if (!isLeaf(n)) temp.push_back(n->val);
            n = n->right ? n->right : n->left;
        }
        for (int i = temp.size()-1; i >= 0; i--) res.push_back(temp[i]);
    }
};
