struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
#include <queue>
using namespace std;
// ============================================================
// Solution 1: Check full, complete, perfect — Recursive — O(N)
// ============================================================
class Solution1 {
public:
    bool isFull(TreeNode* n) { if(!n) return true; if(!n->left&&!n->right) return true; if(n->left&&n->right) return isFull(n->left)&&isFull(n->right); return false; }
    bool isPerfect(TreeNode* root) { int h=0;TreeNode*n=root;while(n){h++;n=n->left;} return countNodes(root)==(1<<h)-1; }
    int countNodes(TreeNode* n) { return n?1+countNodes(n->left)+countNodes(n->right):0; }
};

// ============================================================
// Solution 2: BFS-based checks — O(N)
// ============================================================
class Solution2 {
public:
    bool isComplete(TreeNode* root) {
        if(!root) return true;
        queue<TreeNode*> q; q.push(root); bool seenNull=false;
        while(!q.empty()) { auto n=q.front();q.pop();
            if(!n){seenNull=true;continue;}
            if(seenNull) return false;
            q.push(n->left);q.push(n->right);
        }
        return true;
    }
};
