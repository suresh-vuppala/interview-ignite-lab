struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
using namespace std;
// ============================================================
// Solution 1: Recursive — remove leaves with target value — O(N)
// ============================================================
class Solution1 {
public:
    TreeNode* removeLeafTarget(TreeNode* root, int target) {
        if(!root) return nullptr;
        root->left=removeLeafTarget(root->left,target);
        root->right=removeLeafTarget(root->right,target);
        if(!root->left&&!root->right&&root->val==target) return nullptr;
        return root;
    }
};

// ============================================================
// Solution 2: Iterative postorder with parent tracking — O(N)
// ============================================================
#include <stack>
class Solution2 {
public:
    TreeNode* removeLeafTarget(TreeNode* root, int target) {
        // Repeat until no more leaves to delete (may cascade)
        TreeNode dummy(0); dummy.left=root;
        bool changed=true;
        while(changed) {
            changed=false;
            stack<pair<TreeNode*,TreeNode*>> st; st.push({root,&dummy});
            while(!st.empty()) {
                auto[n,par]=st.top();st.pop();
                if(!n) continue;
                if(!n->left&&!n->right&&n->val==target) {
                    if(par->left==n) par->left=nullptr; else par->right=nullptr;
                    changed=true;
                }
                if(n->right)st.push({n->right,n}); if(n->left)st.push({n->left,n});
            }
            root=dummy.left;
        }
        return root;
    }
};
