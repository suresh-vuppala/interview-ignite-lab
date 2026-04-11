// ============================================================
// Binary Tree Preorder Traversal
// ============================================================

import java.util.*;

class Solution1 {
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        dfs(root, res); return res;
    }
    void dfs(TreeNode n, List<Integer> r) {
        if (n==null) return;
        r.add(n.val); dfs(n.left, r); dfs(n.right, r);
    }
}

class Solution2 {
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        if (root==null) return res;
        Deque<TreeNode> st = new ArrayDeque<>();
        st.push(root);
        while (!st.isEmpty()) {
            TreeNode node = st.pop();
            res.add(node.val);
            if (node.right!=null) st.push(node.right);
            if (node.left!=null) st.push(node.left);
        }
        return res;
    }
}
