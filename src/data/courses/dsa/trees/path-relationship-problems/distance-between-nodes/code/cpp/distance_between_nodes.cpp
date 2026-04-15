struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
using namespace std;
// ============================================================
// Solution 1: Find LCA, then distance from LCA to each — O(N)
// ============================================================
class Solution1 {
    TreeNode* lca(TreeNode* n, int p, int q) {
        if(!n||n->val==p||n->val==q) return n;
        auto l=lca(n->left,p,q),r=lca(n->right,p,q);
        return l&&r?n:l?l:r;
    }
    int dist(TreeNode* n, int target, int d) {
        if(!n) return -1; if(n->val==target) return d;
        int l=dist(n->left,target,d+1); if(l!=-1) return l;
        return dist(n->right,target,d+1);
    }
public:
    int findDistance(TreeNode* root, int p, int q) {
        TreeNode* ancestor = lca(root,p,q);
        return dist(ancestor,p,0)+dist(ancestor,q,0);
    }
};

// ============================================================
// Solution 2: Single DFS — compute distance while finding LCA — O(N)
// ============================================================
class Solution2 {
    int res=-1;
    int dfs(TreeNode* n, int p, int q) {
        if(!n) return -1;
        int l=dfs(n->left,p,q), r=dfs(n->right,p,q);
        int self=(n->val==p||n->val==q)?0:-1;
        if(l>=0&&r>=0){res=l+r+2;return -1;}
        if(self>=0&&(l>=0||r>=0)){res=max(l,r)+1;return -1;}
        if(l>=0) return l+1; if(r>=0) return r+1;
        return self>=0?0:-1;
    }
public:
    int findDistance(TreeNode* root, int p, int q) { res=-1;dfs(root,p,q);return res; }
};
