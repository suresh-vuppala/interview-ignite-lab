// Time: O(N log N) preprocess, O(log N) query | Space: O(N log N)

class TreeAncestor {
    private int[][] up;
    private int LOG = 20;
    
    public TreeAncestor(int n, int[] parent) {
        up = new int[n][LOG];
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < LOG; j++) {
                up[i][j] = -1;
            }
        }
        
        for (int i = 0; i < n; i++) {
            up[i][0] = parent[i];
        }
        
        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i < n; i++) {
                if (up[i][j-1] != -1) {
                    up[i][j] = up[up[i][j-1]][j-1];
                }
            }
        }
    }
    
    public int getKthAncestor(int node, int k) {
        for (int i = 0; i < LOG; i++) {
            if ((k & (1 << i)) != 0) {
                node = up[node][i];
                if (node == -1) return -1;
            }
        }
        return node;
    }
}
