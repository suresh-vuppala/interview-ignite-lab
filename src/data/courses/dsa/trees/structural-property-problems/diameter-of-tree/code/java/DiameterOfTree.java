// ============================================================
// Diameter of Binary Tree
// ============================================================

class Solution {
    int diameter = 0;
    public int diameterOfBinaryTree(TreeNode root) {
        diameter = 0;
        height(root);
        return diameter;
    }
    int height(TreeNode node) {
        if (node == null) return 0;
        int l = height(node.left), r = height(node.right);
        diameter = Math.max(diameter, l + r);
        return 1 + Math.max(l, r);
    }
}
