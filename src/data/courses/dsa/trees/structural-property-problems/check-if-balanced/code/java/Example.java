public class Example {
    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int x) { val = x; }
    }
    
    private int getHeight(TreeNode root) {
        if (root == null) return 0;
        
        int left = getHeight(root.left);
        if (left == -1) return -1;
        
        int right = getHeight(root.right);
        if (right == -1) return -1;
        
        if (Math.abs(left - right) > 1) return -1;
        
        return 1 + Math.max(left, right);
    }
    
    public boolean isBalanced(TreeNode root) {
        return getHeight(root) != -1;
    }
    
    public static void main(String[] args) {
        TreeNode root = new TreeNode(3);
        root.left = new TreeNode(9);
        root.right = new TreeNode(20);
        
        Example sol = new Example();
        System.out.println("Is Balanced: " + sol.isBalanced(root));
    }
}
