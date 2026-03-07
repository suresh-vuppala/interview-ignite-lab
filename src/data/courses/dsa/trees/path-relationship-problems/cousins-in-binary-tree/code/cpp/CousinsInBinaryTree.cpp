#include <queue>
#include <utility>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class CousinsInBinaryTree {
public:
    
    // ==================== SOLUTION 1: DFS TWO PASS ====================
    // Time: O(N) | Space: O(H)
    
    static bool isCousinsDFSTwoPass(TreeNode* root, int x, int y) {
        auto xInfo = findNode(root, x, nullptr, 0);
        auto yInfo = findNode(root, y, nullptr, 0);
        
        if (!xInfo.first || !yInfo.first) return false;
        
        return xInfo.first == yInfo.first && xInfo.second != yInfo.second;
    }
    
    static pair<int, TreeNode*> findNode(TreeNode* node, int target, TreeNode* parent, int depth) {
        if (!node) return {-1, nullptr};
        if (node->val == target) return {depth, parent};
        
        auto left = findNode(node->left, target, node, depth + 1);
        if (left.first != -1) return left;
        return findNode(node->right, target, node, depth + 1);
    }
    
    
    // ==================== SOLUTION 2: DFS SINGLE PASS ====================
    // Time: O(N) | Space: O(H)
    
    static bool isCousinsDFSSinglePass(TreeNode* root, int x, int y) {
        int xDepth = -1, yDepth = -1;
        TreeNode *xParent = nullptr, *yParent = nullptr;
        
        dfs(root, nullptr, 0, x, y, xDepth, yDepth, xParent, yParent);
        
        return xDepth == yDepth && xParent != yParent;
    }
    
    static void dfs(TreeNode* node, TreeNode* parent, int depth, int x, int y,
                   int& xDepth, int& yDepth, TreeNode*& xParent, TreeNode*& yParent) {
        if (!node) return;
        
        if (node->val == x) {
            xDepth = depth;
            xParent = parent;
        }
        if (node->val == y) {
            yDepth = depth;
            yParent = parent;
        }
        
        if (xDepth != -1 && yDepth != -1) return;
        
        dfs(node->left, node, depth + 1, x, y, xDepth, yDepth, xParent, yParent);
        dfs(node->right, node, depth + 1, x, y, xDepth, yDepth, xParent, yParent);
    }
    
    
    // ==================== SOLUTION 3: BFS LEVEL ORDER ====================
    // Time: O(N) | Space: O(W)
    
    static bool isCousins(TreeNode* root, int x, int y) {
        if (!root) return false;
        
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({root, nullptr});
        
        while (!q.empty()) {
            int size = q.size();
            TreeNode *xParent = nullptr, *yParent = nullptr;
            
            for (int i = 0; i < size; i++) {
                auto [node, parent] = q.front();
                q.pop();
                
                if (node->val == x) xParent = parent;
                if (node->val == y) yParent = parent;
                
                if (node->left) q.push({node->left, node});
                if (node->right) q.push({node->right, node});
            }
            
            if (xParent && yParent) {
                return xParent != yParent;
            }
            if (xParent || yParent) {
                return false;
            }
        }
        
        return false;
    }
};
