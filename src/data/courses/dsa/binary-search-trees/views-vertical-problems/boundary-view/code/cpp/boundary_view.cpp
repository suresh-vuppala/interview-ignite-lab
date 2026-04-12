#include <vector>
using namespace std;
struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
class Solution {
public:
    vector<int> boundaryView(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        if (!isLeaf(root)) res.push_back(root->val);
        addLeft(root->left, res); addLeaves(root, res); addRight(root->right, res);
        return res;
    }
    bool isLeaf(TreeNode* n) { return n && !n->left && !n->right; }
    void addLeft(TreeNode* n, vector<int>& r) {
        while (n) { if (!isLeaf(n)) r.push_back(n->val); n = n->left ? n->left : n->right; }
    }
    void addLeaves(TreeNode* n, vector<int>& r) {
        if (!n) return; if (isLeaf(n)) { r.push_back(n->val); return; }
        addLeaves(n->left, r); addLeaves(n->right, r);
    }
    void addRight(TreeNode* n, vector<int>& r) {
        vector<int> temp;
        while (n) { if (!isLeaf(n)) temp.push_back(n->val); n = n->right ? n->right : n->left; }
        for (int i = temp.size()-1; i >= 0; i--) r.push_back(temp[i]);
    }
};
