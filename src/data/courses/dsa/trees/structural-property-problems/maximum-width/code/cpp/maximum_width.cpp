struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
#include <queue>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: BFS with position tracking — O(N)
// ============================================================
class Solution1 {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int maxW=0; queue<pair<TreeNode*,long long>> q; q.push({root,0});
        while(!q.empty()){
            int sz=q.size(); long long left=q.front().second, right=left;
            while(sz--){ auto[n,pos]=q.front();q.pop(); right=pos;
                if(n->left)q.push({n->left,2*pos}); if(n->right)q.push({n->right,2*pos+1}); }
            maxW=max(maxW,(int)(right-left+1));
        }
        return maxW;
    }
};

// ============================================================
// Solution 2: DFS with first position per level — O(N)
// ============================================================
class Solution2 {
    int maxW=0; vector<long long> firstPos;
    void dfs(TreeNode* n, int d, long long pos) {
        if(!n) return;
        if(d>=(int)firstPos.size()) firstPos.push_back(pos);
        maxW=max(maxW,(int)(pos-firstPos[d]+1));
        dfs(n->left,d+1,2*pos); dfs(n->right,d+1,2*pos+1);
    }
public:
    int widthOfBinaryTree(TreeNode* root) { maxW=0; firstPos.clear(); dfs(root,0,0); return maxW; }
};
