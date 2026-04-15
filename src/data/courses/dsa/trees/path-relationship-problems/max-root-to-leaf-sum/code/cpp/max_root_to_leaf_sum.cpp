struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
#include <algorithm>
#include <climits>
using namespace std;
// ============================================================
// Solution 1: DFS recursive — O(N)
// ============================================================
class Solution1 {
public:
    int maxSum(TreeNode* root) {
        if(!root) return 0;
        if(!root->left&&!root->right) return root->val;
        if(!root->left) return root->val+maxSum(root->right);
        if(!root->right) return root->val+maxSum(root->left);
        return root->val+max(maxSum(root->left),maxSum(root->right));
    }
};

// ============================================================
// Solution 2: Iterative DFS with stack — O(N)
// ============================================================
#include <stack>
class Solution2 {
public:
    int maxSum(TreeNode* root) {
        if(!root) return 0;
        int res=INT_MIN; stack<pair<TreeNode*,int>> st; st.push({root,root->val});
        while(!st.empty()) {
            auto[n,sum]=st.top();st.pop();
            if(!n->left&&!n->right) res=max(res,sum);
            if(n->right)st.push({n->right,sum+n->right->val});
            if(n->left)st.push({n->left,sum+n->left->val});
        }
        return res;
    }
};
