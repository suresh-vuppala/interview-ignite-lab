// ============================================================
// Diagonal Traversal
// ============================================================
import java.util.*;
class Solution {
    public List<List<Integer>> diagonalTraversal(TreeNode root) {
        List<List<Integer>> result = new ArrayList<>();
        if (root == null) return result;
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        while (!q.isEmpty()) {
            int size = q.size();
            List<Integer> diag = new ArrayList<>();
            for (int i = 0; i < size; i++) {
                TreeNode node = q.poll();
                while (node != null) {
                    diag.add(node.val);
                    if (node.left != null) q.add(node.left);
                    node = node.right;
                }
            }
            result.add(diag);
        }
        return result;
    }
}
