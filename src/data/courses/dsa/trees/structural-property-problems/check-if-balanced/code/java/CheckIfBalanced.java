// ============================================================
// Balanced Binary Tree
// ============================================================

class Solution1 {
    public boolean isBalanced(TreeNode root) {
        if (root == null) return true;
        return Math.abs(height(root.left)-height(root.right))<=1 && isBalanced(root.left) && isBalanced(root.right);
    }
    int height(TreeNode n) { return n==null ? 0 : 1+Math.max(height(n.left),height(n.right)); }
}

class Solution2 {
    public boolean isBalanced(TreeNode root) { return check(root) != -1; }
    int check(TreeNode n) {
        if (n==null) return 0;
        int l = check(n.left); if (l==-1) return -1;
        int r = check(n.right); if (r==-1) return -1;
        if (Math.abs(l-r)>1) return -1;
        return 1+Math.max(l,r);
    }
}
