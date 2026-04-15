struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
using namespace std;
// ============================================================
// Solution 1: Preorder to array, rebuild — O(N) Time, O(N) Space
// ============================================================
#include <vector>
class Solution1 {
    void preorder(TreeNode* n, vector<TreeNode*>& nodes) {
        if(!n)return; nodes.push_back(n); preorder(n->left,nodes); preorder(n->right,nodes);
    }
public:
    void flatten(TreeNode* root) {
        vector<TreeNode*> nodes; preorder(root,nodes);
        for(int i=0;i<(int)nodes.size()-1;i++) { nodes[i]->left=nullptr; nodes[i]->right=nodes[i+1]; }
    }
};

// ============================================================
// Solution 2: Morris-style — O(N) Time, O(1) Space
// ============================================================
class Solution2 {
public:
    void flatten(TreeNode* root) {
        TreeNode* cur=root;
        while(cur) {
            if(cur->left) {
                TreeNode* pred=cur->left;
                while(pred->right) pred=pred->right;
                pred->right=cur->right;
                cur->right=cur->left;
                cur->left=nullptr;
            }
            cur=cur->right;
        }
    }
};
