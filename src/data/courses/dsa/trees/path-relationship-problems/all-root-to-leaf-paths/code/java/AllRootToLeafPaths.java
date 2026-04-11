// ============================================================
// All Root-to-Leaf Paths
// ============================================================
import java.util.*;
class Solution {
    public List<String> binaryTreePaths(TreeNode root) {
        List<String> result = new ArrayList<>();
        if (root != null) dfs(root, "", result);
        return result;
    }
    void dfs(TreeNode node, String path, List<String> result) {
        path += node.val;
        if (node.left == null && node.right == null) { result.add(path); return; }
        if (node.left != null) dfs(node.left, path + "->", result);
        if (node.right != null) dfs(node.right, path + "->", result);
    }
}
