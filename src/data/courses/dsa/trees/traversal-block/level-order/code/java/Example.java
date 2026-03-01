import java.util.*;

public class Example {
    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int x) { val = x; }
    }
    
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> result = new ArrayList<>();
        if (root == null) return result;
        
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        
        while (!q.isEmpty()) {
            int size = q.size();
            List<Integer> level = new ArrayList<>();
            
            for (int i = 0; i < size; i++) {
                TreeNode node = q.poll();
                level.add(node.val);
                
                if (node.left != null) q.add(node.left);
                if (node.right != null) q.add(node.right);
            }
            result.add(level);
        }
        return result;
    }
    
    public static void main(String[] args) {
        TreeNode root = new TreeNode(3);
        root.left = new TreeNode(9);
        root.right = new TreeNode(20);
        
        Example sol = new Example();
        List<List<Integer>> result = sol.levelOrder(root);
        System.out.println("Level order traversal completed");
    }
}
