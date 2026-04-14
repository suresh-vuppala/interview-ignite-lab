struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
#include <map>
#include <queue>
#include <vector>
using namespace std;
// ============================================================
// Solution 1: DFS with HD → accumulate sum — O(N log N)
// ============================================================
class Solution1 {
    void dfs(TreeNode* n, int hd, map<int,int>& m) {
        if(!n) return; m[hd]+=n->val; dfs(n->left,hd-1,m); dfs(n->right,hd+1,m);
    }
public:
    vector<int> verticalSum(TreeNode* root) {
        map<int,int> m; dfs(root,0,m);
        vector<int> res; for(auto&[k,v]:m) res.push_back(v); return res;
    }
};

// ============================================================
// Solution 2: BFS with HD tracking — O(N log N)
// ============================================================
class Solution2 {
public:
    vector<int> verticalSum(TreeNode* root) {
        if(!root) return {};
        map<int,int> m; queue<pair<TreeNode*,int>> q; q.push({root,0});
        while(!q.empty()){auto[n,hd]=q.front();q.pop();m[hd]+=n->val;if(n->left)q.push({n->left,hd-1});if(n->right)q.push({n->right,hd+1});}
        vector<int> res; for(auto&[k,v]:m)res.push_back(v); return res;
    }
};
