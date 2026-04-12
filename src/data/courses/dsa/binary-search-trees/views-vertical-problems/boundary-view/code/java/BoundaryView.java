import java.util.*;
class Solution {
    public List<Integer> boundaryView(TreeNode root) {
        List<Integer> res = new ArrayList<>(); if (root==null) return res;
        if (!isLeaf(root)) res.add(root.val);
        addLeft(root.left,res); addLeaves(root,res); addRight(root.right,res); return res;
    }
    boolean isLeaf(TreeNode n){return n!=null&&n.left==null&&n.right==null;}
    void addLeft(TreeNode n,List<Integer>r){while(n!=null){if(!isLeaf(n))r.add(n.val);n=n.left!=null?n.left:n.right;}}
    void addLeaves(TreeNode n,List<Integer>r){if(n==null)return;if(isLeaf(n)){r.add(n.val);return;}addLeaves(n.left,r);addLeaves(n.right,r);}
    void addRight(TreeNode n,List<Integer>r){List<Integer>t=new ArrayList<>();while(n!=null){if(!isLeaf(n))t.add(n.val);n=n.right!=null?n.right:n.left;}Collections.reverse(t);r.addAll(t);}
}