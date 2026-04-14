struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
#include <queue>
using namespace std;
// ============================================================
// Solution 1: Recursive comparison — O(N) Time, O(H) Space
// ============================================================
class Solution1 {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p&&!q) return true; if(!p||!q) return false;
        return p->val==q->val && isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
};

// ============================================================
// Solution 2: Iterative BFS comparison — O(N) Time, O(W) Space
// ============================================================
class Solution2 {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> qe; qe.push(p); qe.push(q);
        while(!qe.empty()) {
            auto a=qe.front();qe.pop(); auto b=qe.front();qe.pop();
            if(!a&&!b) continue; if(!a||!b||a->val!=b->val) return false;
            qe.push(a->left);qe.push(b->left);qe.push(a->right);qe.push(b->right);
        }
        return true;
    }
};
