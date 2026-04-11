// ============================================================
// Distance Between Two Nodes
// ============================================================
class Solution {
    public int findDistance(TreeNode root, int p, int q) {
        TreeNode lca = findLCA(root, p, q);
        return depth(lca, p, 0) + depth(lca, q, 0);
    }
    TreeNode findLCA(TreeNode root, int p, int q) {
        if (root==null || root.val==p || root.val==q) return root;
        TreeNode l = findLCA(root.left,p,q), r = findLCA(root.right,p,q);
        return (l!=null && r!=null) ? root : (l!=null ? l : r);
    }
    int depth(TreeNode root, int target, int d) {
        if (root==null) return -1;
        if (root.val==target) return d;
        int l = depth(root.left,target,d+1);
        return l != -1 ? l : depth(root.right,target,d+1);
    }
}
