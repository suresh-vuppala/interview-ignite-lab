struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: Recursive — O(N) Time, O(H) Stack
// ============================================================
class Solution1 {
public:
    void postorder(TreeNode* r, vector<int>& res) { if(!r)return; postorder(r->left,res); postorder(r->right,res); res.push_back(r->val); }
    vector<int> postorderTraversal(TreeNode* r) { vector<int> res; postorder(r,res); return res; }
};

// ============================================================
// Solution 2: Iterative — modified preorder (root-right-left) then reverse
// ============================================================
class Solution2 {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> res; stack<TreeNode*> st; st.push(root);
        while (!st.empty()) { auto n=st.top();st.pop(); res.push_back(n->val); if(n->left)st.push(n->left); if(n->right)st.push(n->right); }
        reverse(res.begin(), res.end()); // root-right-left reversed = left-right-root
        return res;
    }
};
