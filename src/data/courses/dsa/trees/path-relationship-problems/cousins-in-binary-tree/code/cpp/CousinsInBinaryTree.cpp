struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
#include <queue>
using namespace std;
// ============================================================
// Solution 1: BFS — find depth and parent of both nodes — O(N)
// ============================================================
class Solution1 {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if(!root) return false;
        queue<pair<TreeNode*,TreeNode*>> q; q.push({root,nullptr});
        while(!q.empty()) {
            int sz=q.size(); TreeNode *px=nullptr,*py=nullptr;
            while(sz--) {
                auto[n,par]=q.front();q.pop();
                if(n->val==x)px=par; if(n->val==y)py=par;
                if(n->left)q.push({n->left,n}); if(n->right)q.push({n->right,n});
            }
            if(px&&py) return px!=py; // Same depth, different parents
            if(px||py) return false;   // Different depths
        }
        return false;
    }
};

// ============================================================
// Solution 2: DFS — record depth and parent — O(N)
// ============================================================
class Solution2 {
    int dx=-1,dy=-1; TreeNode *px=nullptr,*py=nullptr;
    void dfs(TreeNode* n, TreeNode* par, int d, int x, int y) {
        if(!n) return;
        if(n->val==x){dx=d;px=par;} if(n->val==y){dy=d;py=par;}
        dfs(n->left,n,d+1,x,y); dfs(n->right,n,d+1,x,y);
    }
public:
    bool isCousins(TreeNode* root, int x, int y) { dfs(root,nullptr,0,x,y); return dx==dy&&px!=py; }
};
