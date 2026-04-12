import java.util.*;
class Solution {
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> res = new ArrayList<>(); if (root==null) return res;
        Queue<TreeNode> q = new LinkedList<>(); q.add(root);
        while (!q.isEmpty()) { int s=q.size();
            for (int i=0;i<s;i++) { TreeNode n=q.poll(); if(i==s-1) res.add(n.val);
                if(n.left!=null) q.add(n.left); if(n.right!=null) q.add(n.right); } }
        return res;
    }
}