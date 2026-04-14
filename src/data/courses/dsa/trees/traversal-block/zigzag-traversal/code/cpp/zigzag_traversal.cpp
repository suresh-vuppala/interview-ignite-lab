struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: BFS + reverse alternating levels — O(N)
// ============================================================
class Solution1 {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> res; queue<TreeNode*> q; q.push(root);
        bool leftToRight = true;
        while(!q.empty()) {
            int sz=q.size(); vector<int> level;
            while(sz--){auto n=q.front();q.pop();level.push_back(n->val);if(n->left)q.push(n->left);if(n->right)q.push(n->right);}
            if(!leftToRight) reverse(level.begin(),level.end());
            res.push_back(level); leftToRight=!leftToRight;
        }
        return res;
    }
};

// ============================================================
// Solution 2: BFS with deque — insert front or back — O(N)
// ============================================================
#include <deque>
class Solution2 {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> res; queue<TreeNode*> q; q.push(root);
        bool leftToRight = true;
        while(!q.empty()) {
            int sz=q.size(); deque<int> level;
            while(sz--){auto n=q.front();q.pop();
                if(leftToRight) level.push_back(n->val); else level.push_front(n->val);
                if(n->left)q.push(n->left);if(n->right)q.push(n->right);}
            res.push_back(vector<int>(level.begin(),level.end())); leftToRight=!leftToRight;
        }
        return res;
    }
};
