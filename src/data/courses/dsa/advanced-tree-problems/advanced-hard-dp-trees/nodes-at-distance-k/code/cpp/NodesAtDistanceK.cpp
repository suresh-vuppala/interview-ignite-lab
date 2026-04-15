struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
// ============================================================
// Solution 1: Find target, then DFS up+down tracking distance — O(N)
// ============================================================
class Solution1 {
    unordered_map<TreeNode*, TreeNode*> parentMap;
    void buildParent(TreeNode* n, TreeNode* par) {
        if (!n) return;
        parentMap[n] = par;
        buildParent(n->left, n); buildParent(n->right, n);
    }
    TreeNode* findNode(TreeNode* root, int target) {
        if (!root) return nullptr;
        if (root->val == target) return root;
        auto l = findNode(root->left, target);
        return l ? l : findNode(root->right, target);
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        buildParent(root, nullptr);
        // BFS from target using parent pointers
        queue<TreeNode*> q; q.push(target);
        unordered_map<TreeNode*,bool> visited; visited[target] = true;
        int dist = 0;
        while (!q.empty()) {
            if (dist == k) { vector<int> res; while (!q.empty()) { res.push_back(q.front()->val); q.pop(); } return res; }
            int sz = q.size(); dist++;
            while (sz--) {
                auto n = q.front(); q.pop();
                for (auto next : {n->left, n->right, parentMap[n]})
                    if (next && !visited[next]) { visited[next] = true; q.push(next); }
            }
        }
        return {};
    }
};

// ============================================================
// Solution 2: DFS returning distance — O(N) without parent map
// ============================================================
class Solution2 {
    vector<int> result;
    void collectDown(TreeNode* n, int dist, int k) {
        if (!n) return;
        if (dist == k) { result.push_back(n->val); return; }
        collectDown(n->left, dist+1, k); collectDown(n->right, dist+1, k);
    }
    int dfs(TreeNode* n, TreeNode* target, int k) {
        if (!n) return -1;
        if (n == target) { collectDown(n, 0, k); return 0; }
        int l = dfs(n->left, target, k);
        if (l >= 0) {
            if (l + 1 == k) result.push_back(n->val);
            else collectDown(n->right, l + 2, k);
            return l + 1;
        }
        int r = dfs(n->right, target, k);
        if (r >= 0) {
            if (r + 1 == k) result.push_back(n->val);
            else collectDown(n->left, r + 2, k);
            return r + 1;
        }
        return -1;
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        result.clear(); dfs(root, target, k); return result;
    }
};
