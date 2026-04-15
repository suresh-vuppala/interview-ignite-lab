struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
#include <algorithm>
#include <climits>
using namespace std;
// ============================================================
// Solution 1: DFS with max-so-far tracking — O(N)
// ============================================================
class Solution1 {
    int count=0;
    void dfs(TreeNode* n, int maxVal) {
        if(!n) return;
        if(n->val>=maxVal) count++;
        maxVal=max(maxVal,n->val);
        dfs(n->left,maxVal); dfs(n->right,maxVal);
    }
public:
    int goodNodes(TreeNode* root) { count=0;dfs(root,INT_MIN);return count; }
};

// ============================================================
// Solution 2: Iterative DFS with stack — O(N)
// ============================================================
#include <stack>
class Solution2 {
public:
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        int count=0; stack<pair<TreeNode*,int>> st; st.push({root,INT_MIN});
        while(!st.empty()) {
            auto[n,mx]=st.top();st.pop();
            if(n->val>=mx)count++;
            int newMx=max(mx,n->val);
            if(n->right)st.push({n->right,newMx});
            if(n->left)st.push({n->left,newMx});
        }
        return count;
    }
};
