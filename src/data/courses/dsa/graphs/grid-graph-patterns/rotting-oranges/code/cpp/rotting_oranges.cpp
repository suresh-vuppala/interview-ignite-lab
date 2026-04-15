#include <vector>
#include <queue>
using namespace std;
// ============================================================
// Solution 1: Brute Force — simulate minute by minute — O((M*N)²)
// ============================================================
class Solution1 {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size(), mins=0;
        int dirs[]={0,1,0,-1,0};
        bool changed = true;
        while (changed) {
            changed = false;
            vector<vector<int>> next = grid;
            for(int i=0;i<m;i++) for(int j=0;j<n;j++) if(grid[i][j]==2)
                for(int d=0;d<4;d++) {
                    int ni=i+dirs[d],nj=j+dirs[d+1];
                    if(ni>=0&&ni<m&&nj>=0&&nj<n&&next[ni][nj]==1) { next[ni][nj]=2; changed=true; }
                }
            if(changed) { grid=next; mins++; }
        }
        for(auto& row:grid) for(int x:row) if(x==1) return -1;
        return mins;
    }
};

// ============================================================
// Solution 2: Multi-source BFS — O(M*N) Time
// ============================================================
class Solution2 {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size(), fresh=0, mins=0;
        int dirs[]={0,1,0,-1,0};
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++) for(int j=0;j<n;j++) {
            if(grid[i][j]==2) q.push({i,j});
            else if(grid[i][j]==1) fresh++;
        }
        while(!q.empty() && fresh>0) {
            int sz=q.size(); mins++;
            while(sz--) {
                auto [r,c]=q.front(); q.pop();
                for(int d=0;d<4;d++) {
                    int nr=r+dirs[d],nc=c+dirs[d+1];
                    if(nr>=0&&nr<m&&nc>=0&&nc<n&&grid[nr][nc]==1) {
                        grid[nr][nc]=2; fresh--; q.push({nr,nc});
                    }
                }
            }
        }
        return fresh==0 ? mins : -1;
    }
};
