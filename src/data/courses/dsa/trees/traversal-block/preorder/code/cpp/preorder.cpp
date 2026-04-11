// ============================================================
// Binary Tree Preorder Traversal
// ============================================================

#include <vector>
#include <stack>
using namespace std;

struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };

class Solution1 {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        dfs(root, result); return result;
    }
    void dfs(TreeNode* node, vector<int>& r) {
        if (!node) return;
        r.push_back(node->val); dfs(node->left, r); dfs(node->right, r);
    }
};

class Solution2 {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> result;
        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {
            TreeNode* node = st.top(); st.pop();
            result.push_back(node->val); // Process root first

            // Push right first so left is processed next (LIFO)
            if (node->right) st.push(node->right);
            if (node->left) st.push(node->left);
        }

        return result;
    }
};
