// ============================================================
// Cousins in Binary Tree
// ============================================================
import java.util.*;
class Solution {
    public boolean isCousins(TreeNode root, int x, int y) {
        Queue<int[]> q = new LinkedList<>(); // Using parallel queues
        Queue<TreeNode> nq = new LinkedList<>();
        nq.add(root);
        while (!nq.isEmpty()) {
            int size = nq.size();
            TreeNode xP = null, yP = null;
            for (int i = 0; i < size; i++) {
                TreeNode node = nq.poll();
                if (node.left != null) { nq.add(node.left); if (node.left.val==x) xP=node; if (node.left.val==y) yP=node; }
                if (node.right != null) { nq.add(node.right); if (node.right.val==x) xP=node; if (node.right.val==y) yP=node; }
            }
            if (xP != null && yP != null) return xP != yP;
            if (xP != null || yP != null) return false;
        }
        return false;
    }
}
