struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
#include <vector>
#include <unordered_map>
using namespace std;
// ============================================================
// Solution 1: Linear search for root — O(N²)
// ============================================================
class Solution1 {
    int postIdx;
    TreeNode* build(vector<int>&post,vector<int>&in,int lo,int hi) {
        if(lo>hi)return nullptr;
        TreeNode*node=new TreeNode(post[postIdx--]);
        int mid=lo;while(in[mid]!=node->val)mid++;
        node->right=build(post,in,mid+1,hi); // Right first for postorder!
        node->left=build(post,in,lo,mid-1);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>&inorder,vector<int>&postorder) {postIdx=postorder.size()-1;return build(postorder,inorder,0,inorder.size()-1);}
};

// ============================================================
// Solution 2: HashMap for O(1) lookup — O(N)
// ============================================================
class Solution2 {
    int postIdx;unordered_map<int,int>inMap;
    TreeNode* build(vector<int>&post,int lo,int hi) {
        if(lo>hi)return nullptr;
        TreeNode*node=new TreeNode(post[postIdx--]);
        int mid=inMap[node->val];
        node->right=build(post,mid+1,hi);node->left=build(post,lo,mid-1);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>&inorder,vector<int>&postorder) {
        postIdx=postorder.size()-1;inMap.clear();for(int i=0;i<(int)inorder.size();i++)inMap[inorder[i]]=i;
        return build(postorder,0,inorder.size()-1);
    }
};
