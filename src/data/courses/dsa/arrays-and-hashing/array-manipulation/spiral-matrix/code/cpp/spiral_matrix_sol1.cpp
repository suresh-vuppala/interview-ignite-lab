class Solution {
public:
    // Simulation: O(m×n) space — Track visited cells
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int dirs[4][2] = {{0,1},{1,0},{0,-1},{-1,0}}; // right,down,left,up
        int dir = 0, r = 0, c = 0;
        vector<int> result;
        for (int i = 0; i < m * n; i++) {
            result.push_back(matrix[r][c]);
            visited[r][c] = true;
            int nr = r + dirs[dir][0], nc = c + dirs[dir][1];
            if (nr<0 || nr>=m || nc<0 || nc>=n || visited[nr][nc]) {
                dir = (dir + 1) % 4; // Turn
                nr = r + dirs[dir][0]; nc = c + dirs[dir][1];
            }
            r = nr; c = nc;
        }
        return result;
    }
};