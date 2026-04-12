// ============================================================
// Kth Smallest/Largest
// ============================================================
class Solution {
    int count, result;
    public int kthSmallest(TreeNode root, int k) {
        count = k; result = -1; inorder(root); return result;
    }
    void inorder(TreeNode n) {
        if (n == null || count <= 0) return;
        inorder(n.left);
        if (--count == 0) { result = n.val; return; }
        inorder(n.right);
    }
    public int kthLargest(TreeNode root, int k) {
        count = k; result = -1; revInorder(root); return result;
    }
    void revInorder(TreeNode n) {
        if (n == null || count <= 0) return;
        revInorder(n.right);
        if (--count == 0) { result = n.val; return; }
        revInorder(n.left);
    }
}
