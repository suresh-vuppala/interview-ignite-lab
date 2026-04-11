// ============================================================
// Binary Tree Inorder Traversal
// ============================================================

#include <vector>
#include <stack>
using namespace std;

struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };

// ============================================================
// Solution 1: Recursive
// Time: O(N) | Space: O(H)
// ============================================================
class Solution1 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        dfs(root, result);
        return result;
    }
    void dfs(TreeNode* node, vector<int>& result) {
        if (!node) return;
        dfs(node->left, result);    // Left
        result.push_back(node->val); // Root
        dfs(node->right, result);   // Right
    }
};

// ============================================================
// Solution 2: Iterative with Stack
// Time: O(N) | Space: O(H)
// ============================================================
class Solution2 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* current = root;

        while (current || !st.empty()) {
            // Go as far left as possible
            while (current) {
                st.push(current);
                current = current->left;
            }
            // Process node
            current = st.top(); st.pop();
            result.push_back(current->val);
            // Move to right subtree
            current = current->right;
        }

        return result;
    }
};

// ============================================================
// Solution 3: Morris Traversal (O(1) Space)
// Time: O(N) | Space: O(1)
// ============================================================
class Solution3 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        TreeNode* current = root;

        while (current) {
            if (!current->left) {
                result.push_back(current->val); // Process
                current = current->right;        // Move right
            } else {
                // Find inorder predecessor
                TreeNode* pred = current->left;
                while (pred->right && pred->right != current)
                    pred = pred->right;

                if (!pred->right) {
                    pred->right = current; // Create thread
                    current = current->left;
                } else {
                    pred->right = nullptr; // Remove thread
                    result.push_back(current->val); // Process
                    current = current->right;
                }
            }
        }

        return result;
    }
};
