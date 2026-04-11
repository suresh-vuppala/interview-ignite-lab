// ============================================================
// Binary Tree Maximum Path Sum
// ============================================================
class Solution {
    int globalMax = Integer.MIN_VALUE;
    public int maxPathSum(TreeNode root) {
        globalMax = Integer.MIN_VALUE;
        maxGain(root);
        return globalMax;
    }
    int maxGain(TreeNode node) {
        if (node == null) return 0;
        int left = Math.max(0, maxGain(node.left));
        int right = Math.max(0, maxGain(node.right));
        globalMax = Math.max(globalMax, node.val + left + right);
        return node.val + Math.max(left, right);
    }
}
