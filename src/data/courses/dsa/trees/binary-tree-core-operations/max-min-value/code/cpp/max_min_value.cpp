struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;
// ============================================================
// Solution 1: Recursive — O(N) Time, O(H) Space
// ============================================================
class Solution1 {
public:
    int findMax(TreeNode* root) { if(!root) return INT_MIN; return max({root->val, findMax(root->left), findMax(root->right)}); }
    int findMin(TreeNode* root) { if(!root) return INT_MAX; return min({root->val, findMin(root->left), findMin(root->right)}); }
};

// ============================================================
// Solution 2: Iterative BFS — O(N) Time, O(W) Space
// ============================================================
class Solution2 {
public:
    pair<int,int> findMinMax(TreeNode* root) {
        if (!root) return {INT_MAX, INT_MIN};
        int mn=INT_MAX, mx=INT_MIN;
        queue<TreeNode*> q; q.push(root);
        while(!q.empty()) { auto n=q.front();q.pop(); mn=min(mn,n->val); mx=max(mx,n->val); if(n->left)q.push(n->left); if(n->right)q.push(n->right); }
        return {mn, mx};
    }
};
