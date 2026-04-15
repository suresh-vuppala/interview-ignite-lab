struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
#include <queue>
using namespace std;
// ============================================================
// Solution 1: BFS — find depth-1 level, insert — O(N)
// ============================================================
class Solution1 {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){TreeNode* n=new TreeNode(val);n->left=root;return n;}
        queue<TreeNode*> q; q.push(root); int d=1;
        while(!q.empty()&&d<depth-1){int sz=q.size();while(sz--){auto n=q.front();q.pop();if(n->left)q.push(n->left);if(n->right)q.push(n->right);}d++;}
        while(!q.empty()){auto n=q.front();q.pop();TreeNode*l=new TreeNode(val),*r=new TreeNode(val);l->left=n->left;r->right=n->right;n->left=l;n->right=r;}
        return root;
    }
};

// ============================================================
// Solution 2: DFS recursive — O(N)
// ============================================================
class Solution2 {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){TreeNode* n=new TreeNode(val);n->left=root;return n;}
        if(depth==2){TreeNode*l=new TreeNode(val),*r=new TreeNode(val);l->left=root->left;r->right=root->right;root->left=l;root->right=r;return root;}
        if(root->left) addOneRow(root->left,val,depth-1);
        if(root->right) addOneRow(root->right,val,depth-1);
        return root;
    }
};
