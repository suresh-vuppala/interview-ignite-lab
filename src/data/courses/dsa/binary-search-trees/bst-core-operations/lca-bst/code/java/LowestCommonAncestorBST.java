public class LowestCommonAncestorBST {
    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int x) { val = x; }
    }
    
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if (root == null) return null;
        
        if (p.val < root.val && q.val < root.val)
            return lowestCommonAncestor(root.left, p, q);
        
        if (p.val > root.val && q.val > root.val)
            return lowestCommonAncestor(root.right, p, q);
        
        return root;
    }
    
    public static void main(String[] args) {
        TreeNode root = new TreeNode(6);
        root.left = new TreeNode(2);
        root.right = new TreeNode(8);
        root.left.left = new TreeNode(0);
        root.left.right = new TreeNode(4);
        root.right.left = new TreeNode(7);
        root.right.right = new TreeNode(9);
        
        Example sol = new Example();
        TreeNode lca = sol.lowestCommonAncestor(root, root.left, root.right);
        System.out.println("LCA: " + lca.val);
    }
}
