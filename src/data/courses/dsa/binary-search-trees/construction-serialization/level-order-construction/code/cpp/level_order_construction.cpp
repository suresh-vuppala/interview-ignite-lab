struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
#include <vector>
#include <queue>
using namespace std;
// ============================================================
// Solution 1: Insert one by one into BST — O(N log N) avg
// ============================================================
class Solution1 {
    TreeNode* insert(TreeNode*r,int v){if(!r)return new TreeNode(v);if(v<r->val)r->left=insert(r->left,v);else r->right=insert(r->right,v);return r;}
public:
    TreeNode* buildTree(vector<int>& level) {
        TreeNode*root=nullptr;for(int v:level)root=insert(root,v);return root;
    }
};

// ============================================================
// Solution 2: Queue-based with range bounds — O(N)
// ============================================================
#include <climits>
class Solution2 {
public:
    TreeNode* buildTree(vector<int>& level) {
        if(level.empty())return nullptr;
        TreeNode*root=new TreeNode(level[0]);
        queue<pair<TreeNode*,pair<int,int>>> q; q.push({root,{INT_MIN,INT_MAX}});
        int i=1;
        while(i<(int)level.size()&&!q.empty()){
            auto[node,range]=q.front();q.pop();
            if(i<(int)level.size()&&level[i]>range.first&&level[i]<node->val){
                node->left=new TreeNode(level[i]);q.push({node->left,{range.first,node->val}});i++;
            }
            if(i<(int)level.size()&&level[i]>node->val&&level[i]<range.second){
                node->right=new TreeNode(level[i]);q.push({node->right,{node->val,range.second}});i++;
            }
        }
        return root;
    }
};
