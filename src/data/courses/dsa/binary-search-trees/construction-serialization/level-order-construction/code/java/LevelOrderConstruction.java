import java.util.*;
class Solution {
    public TreeNode buildFromLevelOrder(String[] vals) {
        if (vals.length==0||vals[0].equals("null")) return null;
        TreeNode root = new TreeNode(Integer.parseInt(vals[0]));
        Queue<TreeNode> q = new LinkedList<>(); q.add(root); int i=1;
        while (!q.isEmpty()&&i<vals.length) {
            TreeNode p = q.poll();
            if (i<vals.length&&!vals[i].equals("null")) { p.left=new TreeNode(Integer.parseInt(vals[i])); q.add(p.left); } i++;
            if (i<vals.length&&!vals[i].equals("null")) { p.right=new TreeNode(Integer.parseInt(vals[i])); q.add(p.right); } i++;
        }
        return root;
    }
}