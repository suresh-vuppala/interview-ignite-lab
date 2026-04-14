#include <vector>
#include <queue>
using namespace std;
// ============================================================
// Solution 1: BFS flood fill — O(M*N) Time
// ============================================================
class Solution1 {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int orig = image[sr][sc];
        if (orig == color) return image;  // Avoid infinite loop!
        int m=image.size(), n=image[0].size();
        int dirs[]={0,1,0,-1,0};
        queue<pair<int,int>> q; q.push({sr,sc}); image[sr][sc]=color;
        while (!q.empty()) {
            auto [r,c]=q.front(); q.pop();
            for(int d=0;d<4;d++) {
                int nr=r+dirs[d],nc=c+dirs[d+1];
                if(nr>=0&&nr<m&&nc>=0&&nc<n&&image[nr][nc]==orig) { image[nr][nc]=color; q.push({nr,nc}); }
            }
        }
        return image;
    }
};

// ============================================================
// Solution 2: DFS flood fill — O(M*N) Time, simpler code
// ============================================================
class Solution2 {
    void dfs(vector<vector<int>>& img, int i, int j, int orig, int color) {
        if(i<0||i>=(int)img.size()||j<0||j>=(int)img[0].size()||img[i][j]!=orig) return;
        img[i][j]=color;
        dfs(img,i+1,j,orig,color); dfs(img,i-1,j,orig,color);
        dfs(img,i,j+1,orig,color); dfs(img,i,j-1,orig,color);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color) return image;
        dfs(image,sr,sc,image[sr][sc],color);
        return image;
    }
};
