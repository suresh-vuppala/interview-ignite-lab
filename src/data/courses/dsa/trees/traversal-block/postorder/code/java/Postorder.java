// ============================================================
// Binary Tree Postorder Traversal
// ============================================================

import java.util.*;

class Solution1 {
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        dfs(root, res); return res;
    }
    void dfs(TreeNode n, List<Integer> r) {
        if (n==null) return;
        dfs(n.left, r); dfs(n.right, r); r.add(n.val);
    }
}

class Solution2 {
    public List<Integer> postorderTraversal(TreeNode root) {
        LinkedList<Integer> res = new LinkedList<>();
        if (root==null) return res;
        Deque<TreeNode> st = new ArrayDeque<>();
        st.push(root);
        while (!st.isEmpty()) {
            TreeNode node = st.pop();
            res.addFirst(node.val); // Add to front = reverse
            if (node.left!=null) st.push(node.left);
            if (node.right!=null) st.push(node.right);
        }
        return res;
    }
}
