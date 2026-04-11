// ============================================================
// Path Sum II
// ============================================================
import java.util.*;
class Solution {
    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
        List<List<Integer>> result = new ArrayList<>();
        dfs(root, targetSum, new ArrayList<>(), result);
        return result;
    }
    void dfs(TreeNode node, int remain, List<Integer> path, List<List<Integer>> result) {
        if (node == null) return;
        path.add(node.val); remain -= node.val;
        if (node.left == null && node.right == null && remain == 0)
            result.add(new ArrayList<>(path));
        dfs(node.left, remain, path, result);
        dfs(node.right, remain, path, result);
        path.remove(path.size() - 1); // Backtrack
    }
}
