struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
#include <string>
#include <sstream>
#include <queue>
using namespace std;
// ============================================================
// Solution 1: Preorder recursive serialization — O(N)
// ============================================================
class Solution1 {
public:
    string serialize(TreeNode* root) {
        if(!root) return "#";
        return to_string(root->val)+","+serialize(root->left)+","+serialize(root->right);
    }
};

// ============================================================
// Solution 2: BFS level-order serialization — O(N)
// ============================================================
class Solution2 {
public:
    string serialize(TreeNode* root) {
        if(!root) return "";
        string res; queue<TreeNode*> q; q.push(root);
        while(!q.empty()) {
            auto n=q.front();q.pop();
            if(n){res+=to_string(n->val)+",";q.push(n->left);q.push(n->right);}
            else res+="#,";
        }
        return res;
    }
};
