struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
#include <unordered_map>
using namespace std;
// ============================================================
// Solution 1: From each node, check all downward paths — O(N²)
// ============================================================
class Solution1 {
    int countFrom(TreeNode* n, long rem) {
        if(!n) return 0;
        int c = (rem==n->val) ? 1 : 0;
        return c+countFrom(n->left,rem-n->val)+countFrom(n->right,rem-n->val);
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        return countFrom(root,targetSum)+pathSum(root->left,targetSum)+pathSum(root->right,targetSum);
    }
};

// ============================================================
// Solution 2: Prefix sum + HashMap — O(N) Time, O(N) Space
// ============================================================
class Solution2 {
    int res=0;
    void dfs(TreeNode* n, long prefix, int target, unordered_map<long,int>& m) {
        if(!n) return;
        prefix+=n->val;
        if(m.count(prefix-target)) res+=m[prefix-target];
        m[prefix]++;
        dfs(n->left,prefix,target,m); dfs(n->right,prefix,target,m);
        m[prefix]--;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        res=0; unordered_map<long,int> m; m[0]=1; dfs(root,0,targetSum,m); return res;
    }
};
