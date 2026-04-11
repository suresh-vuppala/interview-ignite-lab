// ============================================================
// Maximum Root-to-Leaf Path Sum
// ============================================================
class Solution {
    public int maxPathSum(TreeNode root) {
        if (root == null) return Integer.MIN_VALUE;
        if (root.left == null && root.right == null) return root.val;
        if (root.left == null) return root.val + maxPathSum(root.right);
        if (root.right == null) return root.val + maxPathSum(root.left);
        return root.val + Math.max(maxPathSum(root.left), maxPathSum(root.right));
    }
}
