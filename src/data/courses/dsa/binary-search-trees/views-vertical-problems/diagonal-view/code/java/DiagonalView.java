import java.util.*;
class Solution {
    public List<List<Integer>> diagonalView(TreeNode root) {
        List<List<Integer>> res = new ArrayList<>(); if(root==null)return res;
        Queue<TreeNode> q = new LinkedList<>(); q.add(root);
        while(!q.isEmpty()){int s=q.size();List<Integer> d=new ArrayList<>();
            for(int i=0;i<s;i++){TreeNode n=q.poll();while(n!=null){d.add(n.val);if(n.left!=null)q.add(n.left);n=n.right;}}
            res.add(d);}return res;
    }
}