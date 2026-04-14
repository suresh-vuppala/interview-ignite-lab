struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
#include <vector>
#include <stack>
using namespace std;
// ============================================================
// Solution 1: Recursive — O(N) Time, O(H) Stack
// ============================================================
class Solution1 {
public:
    void inorder(TreeNode* root, vector<int>& res) {
        if (!root) return;
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
    vector<int> inorderTraversal(TreeNode* root) { vector<int> r; inorder(root,r); return r; }
};

// ============================================================
// Solution 2: Iterative with stack — O(N) Time, O(H) Space
// ============================================================
class Solution2 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res; stack<TreeNode*> st;
        TreeNode* cur = root;
        while (cur || !st.empty()) {
            while (cur) { st.push(cur); cur = cur->left; }
            cur = st.top(); st.pop();
            res.push_back(cur->val);
            cur = cur->right;
        }
        return res;
    }
};
