// ============================================================
// Flood Fill
// ============================================================
class Solution {
    public int[][] floodFill(int[][] image, int sr, int sc, int color) {
        int orig = image[sr][sc];
        if (orig == color) return image;
        dfs(image, sr, sc, orig, color);
        return image;
    }
    void dfs(int[][] img, int i, int j, int orig, int nc) {
        if (i<0||i>=img.length||j<0||j>=img[0].length||img[i][j]!=orig) return;
        img[i][j] = nc;
        dfs(img,i+1,j,orig,nc); dfs(img,i-1,j,orig,nc);
        dfs(img,i,j+1,orig,nc); dfs(img,i,j-1,orig,nc);
    }
}
