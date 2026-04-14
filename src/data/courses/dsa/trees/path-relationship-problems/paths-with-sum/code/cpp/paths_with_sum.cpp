struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
#include <vector>
using namespace std;
// ============================================================
// Solution 1: DFS from each node — O(N²)
// ============================================================
class Solution1 {
    void dfs(TreeNode* n, int target, int cur, vector<vector<int>>& res, vector<int>& path) {
        if(!n) return; cur+=n->val; path.push_back(n->val);
        if(!n->left&&!n->right&&cur==target) res.push_back(path);
        dfs(n->left,target,cur,res,path); dfs(n->right,target,cur,res,path); path.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int target) { vector<vector<int>> res; vector<int> path; dfs(root,target,0,res,path); return res; }
};

// ============================================================
// Solution 2: DFS backtracking — O(N) Time, O(H) Space
// ============================================================
class Solution2 {
    void dfs(TreeNode* n, int rem, vector<int>& path, vector<vector<int>>& res) {
        if(!n) return; path.push_back(n->val); rem-=n->val;
        if(!n->left&&!n->right&&rem==0) res.push_back(path);
        dfs(n->left,rem,path,res); dfs(n->right,rem,path,res); path.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int target) { vector<vector<int>> res; vector<int> path; dfs(root,target,path,res); return res; }
};
