struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
#include <vector>
#include <stack>
using namespace std;
// ============================================================
// Solution 1: Standard iterative inorder with stack — O(N) Time, O(H) Space
// ============================================================
class Solution1 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res; stack<TreeNode*> st; TreeNode* cur=root;
        while(cur||!st.empty()){ while(cur){st.push(cur);cur=cur->left;} cur=st.top();st.pop(); res.push_back(cur->val); cur=cur->right; }
        return res; // Uses O(H) stack space
    }
};

// ============================================================
// Solution 2: Morris Traversal — O(N) Time, O(1) Space!
// ============================================================
class Solution2 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res; TreeNode* cur = root;
        while (cur) {
            if (!cur->left) { res.push_back(cur->val); cur = cur->right; }
            else {
                TreeNode* pred = cur->left;
                while (pred->right && pred->right != cur) pred = pred->right;
                if (!pred->right) { pred->right = cur; cur = cur->left; } // Thread
                else { pred->right = nullptr; res.push_back(cur->val); cur = cur->right; } // Unthread
            }
        }
        return res;
    }
};
