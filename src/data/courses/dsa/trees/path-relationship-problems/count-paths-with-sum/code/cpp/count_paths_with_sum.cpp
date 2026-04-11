// ============================================================
// Path Sum III — Count Paths with Target Sum
// ============================================================
#include <unordered_map>
using namespace std;
struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };

class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long, int> prefixMap;
        prefixMap[0] = 1; // Handle paths starting from root
        return dfs(root, 0, targetSum, prefixMap);
    }
    int dfs(TreeNode* node, long currentSum, int target, unordered_map<long, int>& map) {
        if (!node) return 0;
        currentSum += node->val;
        // Count paths ending here with sum = target
        int count = map.count(currentSum - target) ? map[currentSum - target] : 0;
        map[currentSum]++;
        count += dfs(node->left, currentSum, target, map);
        count += dfs(node->right, currentSum, target, map);
        map[currentSum]--; // Backtrack
        return count;
    }
};
