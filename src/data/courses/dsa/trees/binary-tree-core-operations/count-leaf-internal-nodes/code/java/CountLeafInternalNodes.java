// ============================================================
// Count Leaf and Internal Nodes
// ============================================================

class Solution {
    public int countLeaves(TreeNode root) {
        if (root == null) return 0;
        if (root.left == null && root.right == null) return 1;
        return countLeaves(root.left) + countLeaves(root.right);
    }

    public int countInternal(TreeNode root) {
        if (root == null) return 0;
        if (root.left == null && root.right == null) return 0;
        return 1 + countInternal(root.left) + countInternal(root.right);
    }
}
