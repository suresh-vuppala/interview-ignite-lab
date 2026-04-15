struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
#include <unordered_set>
#include <stack>
using namespace std;
// ============================================================
// Solution 1: Inorder to array, two-pointer — O(N) Space
// ============================================================
#include <vector>
class Solution1 {
    void inorder(TreeNode* n, vector<int>& v) { if(!n)return; inorder(n->left,v); v.push_back(n->val); inorder(n->right,v); }
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> sorted; inorder(root, sorted);
        int l = 0, r = sorted.size()-1;
        while (l < r) {
            int sum = sorted[l] + sorted[r];
            if (sum == k) return true;
            if (sum < k) l++; else r--;
        }
        return false;
    }
};

// ============================================================
// Solution 2: BST iterator (forward + backward) — O(H) Space
// ============================================================
class Solution2 {
public:
    bool findTarget(TreeNode* root, int k) {
        // Two BST iterators: one smallest→largest, one largest→smallest
        stack<TreeNode*> left, right;
        TreeNode* cur = root;
        while (cur) { left.push(cur); cur = cur->left; }
        cur = root;
        while (cur) { right.push(cur); cur = cur->right; }
        while (!left.empty() && !right.empty() && left.top() != right.top()) {
            int sum = left.top()->val + right.top()->val;
            if (sum == k) return true;
            if (sum < k) { // Advance left iterator (next smallest)
                TreeNode* n = left.top(); left.pop(); n = n->right;
                while (n) { left.push(n); n = n->left; }
            } else { // Advance right iterator (next largest)
                TreeNode* n = right.top(); right.pop(); n = n->left;
                while (n) { right.push(n); n = n->right; }
            }
        }
        return false;
    }
};
