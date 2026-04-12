struct TreeNode{int val;TreeNode*left,*right;TreeNode(int v):val(v),left(nullptr),right(nullptr){}};
class Solution{public:int rob(TreeNode*root){auto[skip,take]=dfs(root);return max(skip,take);}
pair<int,int>dfs(TreeNode*n){if(!n)return{0,0};auto[ls,lt]=dfs(n->left);auto[rs,rt]=dfs(n->right);
int skip=max(ls,lt)+max(rs,rt);int take=n->val+ls+rs;return{skip,take};}};