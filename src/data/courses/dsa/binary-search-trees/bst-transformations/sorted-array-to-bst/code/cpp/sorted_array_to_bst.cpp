struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
#include <vector>
using namespace std;
// ============================================================
// Solution 1: Insert elements one by one — O(N log N) avg, O(N²) worst
// ============================================================
class Solution1 {
    TreeNode* insert(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);
        if(val<root->val)root->left=insert(root->left,val);else root->right=insert(root->right,val);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = nullptr;
        for (int v : nums) root = insert(root, v);
        return root;  // May be unbalanced!
    }
};

// ============================================================
// Solution 2: Mid-split recursion — guaranteed balanced — O(N)
// ============================================================
class Solution2 {
    TreeNode* build(vector<int>& nums, int lo, int hi) {
        if (lo > hi) return nullptr;
        int mid = lo + (hi - lo) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = build(nums, lo, mid - 1);
        node->right = build(nums, mid + 1, hi);
        return node;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) { return build(nums, 0, nums.size()-1); }
};
