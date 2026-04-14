struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
using namespace std;
// ============================================================
// Solution 1: Inorder to array, build DLL — O(N) Time+Space
// ============================================================
#include <vector>
class Solution1 {
    void inorder(TreeNode* n, vector<TreeNode*>& nodes) {
        if(!n)return; inorder(n->left,nodes); nodes.push_back(n); inorder(n->right,nodes);
    }
public:
    TreeNode* treeToDoublyList(TreeNode* root) {
        vector<TreeNode*> nodes; inorder(root,nodes);
        for(int i=0;i<(int)nodes.size();i++) {
            nodes[i]->left=(i>0)?nodes[i-1]:nullptr;
            nodes[i]->right=(i<(int)nodes.size()-1)?nodes[i+1]:nullptr;
        }
        return nodes.empty()?nullptr:nodes[0];
    }
};

// ============================================================
// Solution 2: In-place inorder with prev pointer — O(N) Time, O(H) Space
// ============================================================
class Solution2 {
    TreeNode* prev=nullptr, *head=nullptr;
    void inorder(TreeNode* n) {
        if(!n)return; inorder(n->left);
        if(!prev) head=n; else { prev->right=n; n->left=prev; }
        prev=n; inorder(n->right);
    }
public:
    TreeNode* treeToDoublyList(TreeNode* root) { prev=head=nullptr; inorder(root); return head; }
};
