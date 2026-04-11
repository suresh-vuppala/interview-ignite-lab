// ============================================================
// Flood Fill
// ============================================================
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int origColor = image[sr][sc];
        if (origColor == color) return image; // No-op — prevent infinite loop
        dfs(image, sr, sc, origColor, color);
        return image;
    }
    void dfs(vector<vector<int>>& img, int i, int j, int orig, int newC) {
        if (i<0||i>=(int)img.size()||j<0||j>=(int)img[0].size()||img[i][j]!=orig) return;
        img[i][j] = newC;
        dfs(img,i+1,j,orig,newC); dfs(img,i-1,j,orig,newC);
        dfs(img,i,j+1,orig,newC); dfs(img,i,j-1,orig,newC);
    }
};
