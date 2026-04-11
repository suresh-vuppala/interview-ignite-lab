class Solution {
    public int goodNodes(TreeNode root) {
        return dfs(root, root.val);
    }
    private int dfs(TreeNode node, int maxSoFar) {
        if (node == null) return 0;
        int count = node.val >= maxSoFar ? 1 : 0;
        int newMax = Math.max(maxSoFar, node.val);
        return count + dfs(node.left, newMax) + dfs(node.right, newMax);
    }
}