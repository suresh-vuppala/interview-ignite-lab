struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
#include <vector>
#include <stack>
using namespace std;
// ============================================================
// Solution 1: Recursive — O(N) Time, O(H) Stack Space
// ============================================================
class Solution1 {
public:
    void inorder(TreeNode* root, vector<int>& res) {
        if (!root) return;
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
    vector<int> inorderTraversal(TreeNode* root) { vector<int> r; inorder(root, r); return r; }
};

// ============================================================
// Solution 2: Iterative with Stack — O(N) Time, O(H) Space
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

// ============================================================
// Solution 3: Morris Traversal — O(N) Time, O(1) Space!
// ============================================================
class Solution3 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode* cur = root;
        while (cur) {
            if (!cur->left) {
                res.push_back(cur->val); // Visit node
                cur = cur->right;
            } else {
                // Find inorder predecessor (rightmost in left subtree)
                TreeNode* pred = cur->left;
                while (pred->right && pred->right != cur) pred = pred->right;

                if (!pred->right) {
                    pred->right = cur;   // Create thread: predecessor → current
                    cur = cur->left;     // Move left
                } else {
                    pred->right = nullptr;       // Remove thread (restore tree)
                    res.push_back(cur->val);     // Visit node
                    cur = cur->right;            // Move right
                }
            }
        }
        return res;
        // Key insight: uses tree structure itself as stack via temporary "threads"
        // No extra space — modifies tree temporarily, restores it fully
    }
};
