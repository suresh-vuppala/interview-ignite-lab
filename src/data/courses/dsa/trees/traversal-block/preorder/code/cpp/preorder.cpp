struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
#include <vector>
#include <stack>
using namespace std;
// ============================================================
// Solution 1: Recursive — O(N) Time, O(H) Stack
// ============================================================
class Solution1 {
public:
    void preorder(TreeNode* r, vector<int>& res) { if(!r)return; res.push_back(r->val); preorder(r->left,res); preorder(r->right,res); }
    vector<int> preorderTraversal(TreeNode* r) { vector<int> res; preorder(r,res); return res; }
};

// ============================================================
// Solution 2: Iterative with stack — O(N) Time, O(H) Space
// ============================================================
class Solution2 {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> res; stack<TreeNode*> st; st.push(root);
        while (!st.empty()) { auto n=st.top();st.pop(); res.push_back(n->val); if(n->right)st.push(n->right); if(n->left)st.push(n->left); }
        return res;
    }
};
