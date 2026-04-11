// ============================================================
// Binary Tree Inorder Traversal
// ============================================================

import java.util.*;

class Solution1 {
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        dfs(root, res); return res;
    }
    void dfs(TreeNode n, List<Integer> r) {
        if (n==null) return;
        dfs(n.left, r); r.add(n.val); dfs(n.right, r);
    }
}

class Solution2 {
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        Deque<TreeNode> st = new ArrayDeque<>();
        TreeNode cur = root;
        while (cur != null || !st.isEmpty()) {
            while (cur != null) { st.push(cur); cur = cur.left; }
            cur = st.pop(); res.add(cur.val); cur = cur.right;
        }
        return res;
    }
}

class Solution3 {
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        TreeNode cur = root;
        while (cur != null) {
            if (cur.left == null) { res.add(cur.val); cur = cur.right; }
            else {
                TreeNode pred = cur.left;
                while (pred.right != null && pred.right != cur) pred = pred.right;
                if (pred.right == null) { pred.right = cur; cur = cur.left; }
                else { pred.right = null; res.add(cur.val); cur = cur.right; }
            }
        }
        return res;
    }
}
