// ============================================================
// Max and Min Value in Binary Tree
// ============================================================

class Solution1 {
    public int findMax(TreeNode root) {
        if (root == null) return Integer.MIN_VALUE;
        return Math.max(root.val, Math.max(findMax(root.left), findMax(root.right)));
    }
    public int findMin(TreeNode root) {
        if (root == null) return Integer.MAX_VALUE;
        return Math.min(root.val, Math.min(findMin(root.left), findMin(root.right)));
    }
}

class Solution2 {
    public int findBSTMin(TreeNode root) { while (root.left!=null) root=root.left; return root.val; }
    public int findBSTMax(TreeNode root) { while (root.right!=null) root=root.right; return root.val; }
}
