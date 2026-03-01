public class Example {
    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int x) { val = x; }
    }
    
    static class MinMax {
        int min, max;
        MinMax(int mn, int mx) { min = mn; max = mx; }
    }
    
    static MinMax findMinMax(TreeNode root) {
        if (root == null) 
            return new MinMax(Integer.MAX_VALUE, Integer.MIN_VALUE);
        
        MinMax left = findMinMax(root.left);
        MinMax right = findMinMax(root.right);
        
        int min = Math.min(root.val, Math.min(left.min, right.min));
        int max = Math.max(root.val, Math.max(left.max, right.max));
        
        return new MinMax(min, max);
    }
    
    public static void main(String[] args) {
        TreeNode root = new TreeNode(10);
        root.left = new TreeNode(5);
        root.right = new TreeNode(15);
        MinMax result = findMinMax(root);
        System.out.println("Min: " + result.min + ", Max: " + result.max);
    }
}
