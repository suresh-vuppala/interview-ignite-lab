import java.util.*;

public class Example {
    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int x) { val = x; }
    }
    
    static List<Integer> preorder(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        preorderHelper(root, result);
        return result;
    }
    
    static void preorderHelper(TreeNode root, List<Integer> result) {
        if (root == null) return;
        result.add(root.val);
        preorderHelper(root.left, result);
        preorderHelper(root.right, result);
    }
    
    static List<Integer> preorderIterative(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        if (root == null) return result;
        
        Stack<TreeNode> st = new Stack<>();
        st.push(root);
        
        while (!st.isEmpty()) {
            TreeNode curr = st.pop();
            result.add(curr.val);
            if (curr.right != null) st.push(curr.right);
            if (curr.left != null) st.push(curr.left);
        }
        return result;
    }
    
    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        System.out.println(preorder(root));
    }
}
