struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
#include <vector>
#include <unordered_map>
using namespace std;
// ============================================================
// Solution 1: Search for root in inorder each time — O(N²)
// ============================================================
class Solution1 {
    int preIdx=0;
    TreeNode* build(vector<int>&pre,vector<int>&in,int lo,int hi) {
        if(lo>hi)return nullptr;
        TreeNode*node=new TreeNode(pre[preIdx++]);
        int mid=lo;while(in[mid]!=node->val)mid++; // O(N) search!
        node->left=build(pre,in,lo,mid-1);node->right=build(pre,in,mid+1,hi);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>&preorder,vector<int>&inorder) {preIdx=0;return build(preorder,inorder,0,inorder.size()-1);}
};

// ============================================================
// Solution 2: HashMap for O(1) root index lookup — O(N)
// ============================================================
class Solution2 {
    int preIdx=0;
    unordered_map<int,int> inMap;
    TreeNode* build(vector<int>&pre,int lo,int hi) {
        if(lo>hi)return nullptr;
        TreeNode*node=new TreeNode(pre[preIdx++]);
        int mid=inMap[node->val]; // O(1) lookup!
        node->left=build(pre,lo,mid-1);node->right=build(pre,mid+1,hi);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>&preorder,vector<int>&inorder) {
        preIdx=0;inMap.clear();for(int i=0;i<(int)inorder.size();i++)inMap[inorder[i]]=i;
        return build(preorder,0,inorder.size()-1);
    }
};
