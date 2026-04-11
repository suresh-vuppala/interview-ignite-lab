// ============================================================
// Path Sum III
// ============================================================
import java.util.*;
class Solution {
    public int pathSum(TreeNode root, int targetSum) {
        Map<Long, Integer> map = new HashMap<>();
        map.put(0L, 1);
        return dfs(root, 0, targetSum, map);
    }
    int dfs(TreeNode node, long curSum, int target, Map<Long, Integer> map) {
        if (node == null) return 0;
        curSum += node.val;
        int count = map.getOrDefault(curSum - target, 0);
        map.merge(curSum, 1, Integer::sum);
        count += dfs(node.left, curSum, target, map);
        count += dfs(node.right, curSum, target, map);
        map.merge(curSum, -1, Integer::sum); // Backtrack
        return count;
    }
}
