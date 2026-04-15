struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: BFS then reverse — O(N) Time
// ============================================================
class Solution1 {
public:
    vector<vector<int>> reverseLevelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> res; queue<TreeNode*> q; q.push(root);
        while (!q.empty()) {
            int sz=q.size(); vector<int> level;
            while(sz--){auto n=q.front();q.pop();level.push_back(n->val);if(n->left)q.push(n->left);if(n->right)q.push(n->right);}
            res.push_back(level);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

// ============================================================
// Solution 2: DFS with depth + reverse — O(N) Time
// ============================================================
class Solution2 {
    void dfs(TreeNode* n, int d, vector<vector<int>>& res) {
        if(!n) return;
        if(d>=(int)res.size()) res.push_back({});
        res[d].push_back(n->val);
        dfs(n->left,d+1,res); dfs(n->right,d+1,res);
    }
public:
    vector<vector<int>> reverseLevelOrder(TreeNode* root) {
        vector<vector<int>> res; dfs(root,0,res); reverse(res.begin(),res.end()); return res;
    }
};
