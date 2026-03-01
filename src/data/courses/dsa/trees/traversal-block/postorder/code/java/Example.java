import java.util.*;

public class Example {
    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int x) { val = x; }
    }
    
    static List<Integer> postorder(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        postorderHelper(root, result);
        return result;
    }
    
    static void postorderHelper(TreeNode root, List<Integer> result) {
        if (root == null) return;
        postorderHelper(root.left, result);
        postorderHelper(root.right, result);
        result.add(root.val);
    }
    
    static List<Integer> postorderIterative(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        if (root == null) return result;
        
        Stack<TreeNode> st = new Stack<>();
        TreeNode curr = root, lastVisited = null;
        
        while (curr != null || !st.isEmpty()) {
            while (curr != null) {
                st.push(curr);
                curr = curr.left;
            }
            TreeNode top = st.peek();
            if (top.right != null && top.right != lastVisited) {
                curr = top.right;
            } else {
                result.add(top.val);
                lastVisited = st.pop();
            }
        }
        return result;
    }
    
    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        System.out.println(postorder(root));
    }
}
