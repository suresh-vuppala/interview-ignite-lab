// ============================================================
// Kth Ancestor
// ============================================================
import java.util.*;
class Solution {
    public int findKthAncestor(TreeNode root, int target, int k) {
        List<TreeNode> path = new ArrayList<>();
        findPath(root, target, path);
        int idx = path.size() - 1 - k;
        return idx >= 0 ? path.get(idx).val : -1;
    }
    boolean findPath(TreeNode node, int target, List<TreeNode> path) {
        if (node == null) return false;
        path.add(node);
        if (node.val == target) return true;
        if (findPath(node.left, target, path) || findPath(node.right, target, path)) return true;
        path.remove(path.size()-1);
        return false;
    }
}
