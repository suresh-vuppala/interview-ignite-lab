#include <vector>
#include <queue>
using namespace std;
// ============================================================
// Solution 1: DFS from each cell to check both oceans — O(M²*N²)
// ============================================================
class Solution1 {
    int m,n;
    bool canReach(vector<vector<int>>&h,int si,int sj,bool pacific){
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        queue<pair<int,int>>q;q.push({si,sj});vis[si][sj]=true;
        int dirs[]={0,1,0,-1,0};
        while(!q.empty()){auto[r,c]=q.front();q.pop();
            if(pacific&&(r==0||c==0))return true;
            if(!pacific&&(r==m-1||c==n-1))return true;
            for(int d=0;d<4;d++){int nr=r+dirs[d],nc=c+dirs[d+1];
                if(nr>=0&&nr<m&&nc>=0&&nc<n&&!vis[nr][nc]&&h[nr][nc]<=h[r][c]){vis[nr][nc]=true;q.push({nr,nc});}}}
        return false;
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>&heights){
        m=heights.size();n=heights[0].size();
        vector<vector<int>>result;
        for(int i=0;i<m;i++)for(int j=0;j<n;j++)
            if(canReach(heights,i,j,true)&&canReach(heights,i,j,false))result.push_back({i,j});
        return result;
    }
};

// ============================================================
// Solution 2: BFS from ocean borders (reverse flow) — O(M*N)
// ============================================================
class Solution2 {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>&heights){
        int m=heights.size(),n=heights[0].size();
        vector<vector<bool>>pac(m,vector<bool>(n,false)),atl(m,vector<bool>(n,false));
        int dirs[]={0,1,0,-1,0};
        auto bfs=[&](queue<pair<int,int>>&q,vector<vector<bool>>&reach){
            while(!q.empty()){auto[r,c]=q.front();q.pop();
                for(int d=0;d<4;d++){int nr=r+dirs[d],nc=c+dirs[d+1];
                    if(nr>=0&&nr<m&&nc>=0&&nc<n&&!reach[nr][nc]&&heights[nr][nc]>=heights[r][c]){reach[nr][nc]=true;q.push({nr,nc});}}}
        };
        queue<pair<int,int>>pq,aq;
        for(int i=0;i<m;i++){pac[i][0]=true;pq.push({i,0});atl[i][n-1]=true;aq.push({i,n-1});}
        for(int j=0;j<n;j++){pac[0][j]=true;pq.push({0,j});atl[m-1][j]=true;aq.push({m-1,j});}
        bfs(pq,pac);bfs(aq,atl);
        vector<vector<int>>result;
        for(int i=0;i<m;i++)for(int j=0;j<n;j++)if(pac[i][j]&&atl[i][j])result.push_back({i,j});
        return result;
    }
};
