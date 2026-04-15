struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
#include <vector>
using namespace std;
// ============================================================
// Solution 1: Collect left boundary + leaves + right boundary
// ============================================================
class Solution1 {
    void leftBoundary(TreeNode* n, vector<int>& res) { if(!n||(!n->left&&!n->right))return; res.push_back(n->val); if(n->left)leftBoundary(n->left,res); else leftBoundary(n->right,res); }
    void leaves(TreeNode* n, vector<int>& res) { if(!n)return; if(!n->left&&!n->right){res.push_back(n->val);return;} leaves(n->left,res); leaves(n->right,res); }
    void rightBoundary(TreeNode* n, vector<int>& res) { if(!n||(!n->left&&!n->right))return; if(n->right)rightBoundary(n->right,res); else rightBoundary(n->left,res); res.push_back(n->val); }
public:
    vector<int> boundaryTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> res = {root->val};
        leftBoundary(root->left, res); leaves(root->left, res); leaves(root->right, res); rightBoundary(root->right, res);
        return res;
    }
};

// ============================================================
// Solution 2: Iterative approach — same three parts
// ============================================================
class Solution2 {
public:
    vector<int> boundaryTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> res = {root->val};
        // Left boundary (excluding leaves)
        TreeNode* n = root->left;
        while(n) { if(n->left||n->right)res.push_back(n->val); n=n->left?n->left:n->right; }
        // Leaves via DFS
        function<void(TreeNode*)> addLeaves = [&](TreeNode* node) { if(!node)return; if(!node->left&&!node->right)res.push_back(node->val); addLeaves(node->left); addLeaves(node->right); };
        addLeaves(root->left); addLeaves(root->right);
        // Right boundary (reverse, excluding leaves)
        vector<int> right;
        n = root->right;
        while(n) { if(n->left||n->right)right.push_back(n->val); n=n->right?n->right:n->left; }
        for(int i=right.size()-1;i>=0;i--) res.push_back(right[i]);
        return res;
    }
};
