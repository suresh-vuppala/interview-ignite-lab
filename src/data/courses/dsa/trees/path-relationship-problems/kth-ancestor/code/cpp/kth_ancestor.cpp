struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
using namespace std;
// ============================================================
// Solution 1: Find path from root, return K-th from end — O(N)
// ============================================================
#include <vector>
class Solution1 {
    bool findPath(TreeNode* n, int target, vector<TreeNode*>& path) {
        if(!n) return false; path.push_back(n);
        if(n->val==target) return true;
        if(findPath(n->left,target,path)||findPath(n->right,target,path)) return true;
        path.pop_back(); return false;
    }
public:
    int kthAncestor(TreeNode* root, int target, int k) {
        vector<TreeNode*> path; findPath(root,target,path);
        int idx=path.size()-1-k;
        return idx>=0?path[idx]->val:-1;
    }
};

// ============================================================
// Solution 2: DFS returning depth — O(N)
// ============================================================
class Solution2 {
    int res=-1;
    int dfs(TreeNode* n, int target, int k) {
        if(!n) return -1; if(n->val==target) return 0;
        int l=dfs(n->left,target,k), r=dfs(n->right,target,k);
        int d=(l>=0)?l+1:(r>=0)?r+1:-1;
        if(d==k) res=n->val;
        return d;
    }
public:
    int kthAncestor(TreeNode* root, int target, int k) { res=-1;dfs(root,target,k);return res; }
};
