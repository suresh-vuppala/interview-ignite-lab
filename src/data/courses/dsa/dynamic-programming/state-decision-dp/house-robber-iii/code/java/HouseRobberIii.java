class Solution{public int rob(TreeNode root){int[]r=dfs(root);return Math.max(r[0],r[1]);}
int[]dfs(TreeNode n){if(n==null)return new int[]{0,0};int[]l=dfs(n.left),r=dfs(n.right);
int skip=Math.max(l[0],l[1])+Math.max(r[0],r[1]);int take=n.val+l[0]+r[0];return new int[]{skip,take};}}