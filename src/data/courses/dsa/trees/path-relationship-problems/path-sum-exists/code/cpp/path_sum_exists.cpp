struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
using namespace std;
// ============================================================
// Solution 1: Recursive DFS — O(N) Time, O(H) Space
// ============================================================
class Solution1 {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        if(!root->left&&!root->right) return root->val==targetSum;
        return hasPathSum(root->left,targetSum-root->val) || hasPathSum(root->right,targetSum-root->val);
    }
};

// ============================================================
// Solution 2: Iterative DFS with stack — O(N) Time, O(H) Space
// ============================================================
#include <stack>
class Solution2 {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        stack<pair<TreeNode*,int>> st; st.push({root,targetSum});
        while(!st.empty()) {
            auto [n,rem] = st.top(); st.pop();
            if(!n->left&&!n->right&&n->val==rem) return true;
            if(n->right) st.push({n->right,rem-n->val});
            if(n->left) st.push({n->left,rem-n->val});
        }
        return false;
    }
};
