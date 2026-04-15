struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
#include <vector>
using namespace std;
// ============================================================
// Solution 1: Three separate traversals — left boundary + leaves + right boundary
// ============================================================
class Solution1 {
    void leftBound(TreeNode*n,vector<int>&r){if(!n||(!n->left&&!n->right))return;r.push_back(n->val);if(n->left)leftBound(n->left,r);else leftBound(n->right,r);}
    void leaves(TreeNode*n,vector<int>&r){if(!n)return;if(!n->left&&!n->right){r.push_back(n->val);return;}leaves(n->left,r);leaves(n->right,r);}
    void rightBound(TreeNode*n,vector<int>&r){if(!n||(!n->left&&!n->right))return;if(n->right)rightBound(n->right,r);else rightBound(n->left,r);r.push_back(n->val);}
public:
    vector<int> boundary(TreeNode* root) {
        if(!root)return {};vector<int>r={root->val};
        leftBound(root->left,r);leaves(root->left,r);leaves(root->right,r);rightBound(root->right,r);return r;
    }
};

// ============================================================
// Solution 2: Single DFS with flags — O(N) Time
// ============================================================
class Solution2 {
    void dfs(TreeNode*n,bool isLeft,bool isRight,vector<int>&r){
        if(!n)return;
        if(isLeft||(!n->left&&!n->right))r.push_back(n->val);
        dfs(n->left,isLeft,isRight&&!n->left,r);
        dfs(n->right,isLeft&&!n->right,isRight,r);
        if(isRight&&!isLeft&&(n->left||n->right))r.push_back(n->val);
    }
public:
    vector<int> boundary(TreeNode* root) { if(!root)return {};vector<int>r;dfs(root,true,true,r);return r; }
};
