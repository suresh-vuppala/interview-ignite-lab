// Time: O(N) | Space: O(H)

#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x = 0) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    int diameter = 0;
    
    int dfs(TreeNode* node) {
        if (!node) return 0;
        
        int left = dfs(node->left);
        int right = dfs(node->right);
        
        diameter = max(diameter, left + right);
        return max(left, right) + 1;
    }
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return diameter;
    }
};
