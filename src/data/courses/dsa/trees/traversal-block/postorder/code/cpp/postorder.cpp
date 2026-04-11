// ============================================================
// Binary Tree Postorder Traversal
// ============================================================

#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };

class Solution1 {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        dfs(root, result); return result;
    }
    void dfs(TreeNode* node, vector<int>& r) {
        if (!node) return;
        dfs(node->left, r); dfs(node->right, r); r.push_back(node->val);
    }
};

class Solution2 {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> result;
        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {
            TreeNode* node = st.top(); st.pop();
            result.push_back(node->val);
            // Push LEFT first (so RIGHT is processed next → Root→R→L)
            if (node->left) st.push(node->left);
            if (node->right) st.push(node->right);
        }

        // Reverse: Root→R→L becomes L→R→Root = Postorder
        reverse(result.begin(), result.end());
        return result;
    }
};
