// ============================================================
// Tree Type Checks
// ============================================================
import java.util.*;
class Solution {
    public boolean isFullTree(TreeNode root) {
        if (root == null) return true;
        if ((root.left==null) != (root.right==null)) return false;
        return isFullTree(root.left) && isFullTree(root.right);
    }
    public boolean isComplete(TreeNode root) {
        if (root == null) return true;
        Queue<TreeNode> q = new LinkedList<>(); q.add(root);
        boolean flag = false;
        while (!q.isEmpty()) {
            TreeNode n = q.poll();
            if (n.left != null) { if (flag) return false; q.add(n.left); } else flag = true;
            if (n.right != null) { if (flag) return false; q.add(n.right); } else flag = true;
        }
        return true;
    }
    public boolean isPerfect(TreeNode root) {
        int lh = 0, rh = 0;
        TreeNode l = root, r = root;
        while (l != null) { lh++; l = l.left; }
        while (r != null) { rh++; r = r.right; }
        return lh == rh;
    }
}
