// ============================================================
// Add One Row to Tree
// ============================================================
class Solution {
    public TreeNode addOneRow(TreeNode root, int val, int depth) {
        if (depth == 1) { TreeNode n = new TreeNode(val); n.left = root; return n; }
        dfs(root, val, depth, 1);
        return root;
    }
    void dfs(TreeNode node, int val, int depth, int cur) {
        if (node == null) return;
        if (cur == depth - 1) {
            TreeNode nl = new TreeNode(val), nr = new TreeNode(val);
            nl.left = node.left; nr.right = node.right;
            node.left = nl; node.right = nr;
            return;
        }
        dfs(node.left, val, depth, cur+1);
        dfs(node.right, val, depth, cur+1);
    }
}
