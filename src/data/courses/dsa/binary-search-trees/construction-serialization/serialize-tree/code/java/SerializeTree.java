import java.util.*;
class Solution {
    public String serialize(TreeNode root) {
        if (root == null) return "null";
        StringBuilder sb = new StringBuilder();
        Queue<TreeNode> q = new LinkedList<>(); q.add(root);
        while (!q.isEmpty()) {
            TreeNode n = q.poll();
            if (n != null) { sb.append(n.val).append(","); q.add(n.left); q.add(n.right); }
            else sb.append("null,");
        }
        return sb.toString();
    }
}