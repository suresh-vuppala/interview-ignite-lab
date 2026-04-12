import java.util.*;
class Solution {
    Map<Integer,Integer> map = new HashMap<>(); int postIdx;
    public TreeNode buildTree(int[] in, int[] post) {
        for (int i=0;i<in.length;i++) map.put(in[i],i);
        postIdx=post.length-1; return build(post,0,in.length-1);
    }
    TreeNode build(int[] post, int l, int r) {
        if (l>r) return null;
        TreeNode root = new TreeNode(post[postIdx--]);
        int idx = map.get(root.val);
        root.right = build(post, idx+1, r);
        root.left = build(post, l, idx-1);
        return root;
    }
}