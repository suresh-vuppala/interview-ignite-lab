struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
#include <vector>
#include <stack>
using namespace std;
// ============================================================
// Solution 1: Inorder to array, index K — O(N) Time+Space
// ============================================================
class Solution1 {
    void inorder(TreeNode* n, vector<int>& v) { if(!n)return; inorder(n->left,v); v.push_back(n->val); inorder(n->right,v); }
public:
    int kthSmallest(TreeNode* root, int k) { vector<int> v; inorder(root,v); return v[k-1]; }
    int kthLargest(TreeNode* root, int k) { vector<int> v; inorder(root,v); return v[v.size()-k]; }
};

// ============================================================
// Solution 2: Iterative inorder — stop at K — O(H+K) Time, O(H) Space
// ============================================================
class Solution2 {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st; TreeNode* cur = root;
        while (cur || !st.empty()) {
            while (cur) { st.push(cur); cur = cur->left; }
            cur = st.top(); st.pop();
            if (--k == 0) return cur->val;
            cur = cur->right;
        }
        return -1;
    }
};
