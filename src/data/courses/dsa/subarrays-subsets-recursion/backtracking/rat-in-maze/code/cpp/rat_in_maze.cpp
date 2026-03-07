// Time: O(4^(N×M)), Space: O(N×M)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> findPath(vector<vector<int>>& maze) {
        vector<string> result;
        int n = maze.size();
        if (n == 0 || maze[0][0] == 0 || maze[n-1][n-1] == 0) return result;
        
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        backtrack(maze, 0, 0, n, "", visited, result);
        return result;
    }
    
private:
    void backtrack(vector<vector<int>>& maze, int i, int j, int n, string path, vector<vector<bool>>& visited, vector<string>& result) {
        if (i == n-1 && j == n-1) {
            result.push_back(path);
            return;
        }
        
        visited[i][j] = true;
        
        if (i+1 < n && maze[i+1][j] == 1 && !visited[i+1][j]) backtrack(maze, i+1, j, n, path+"D", visited, result);
        if (j-1 >= 0 && maze[i][j-1] == 1 && !visited[i][j-1]) backtrack(maze, i, j-1, n, path+"L", visited, result);
        if (j+1 < n && maze[i][j+1] == 1 && !visited[i][j+1]) backtrack(maze, i, j+1, n, path+"R", visited, result);
        if (i-1 >= 0 && maze[i-1][j] == 1 && !visited[i-1][j]) backtrack(maze, i-1, j, n, path+"U", visited, result);
        
        visited[i][j] = false;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> maze = {{1,0,0,0},{1,1,0,1},{0,1,0,0},{1,1,1,1}};
    vector<string> result = sol.findPath(maze);
    for (string path : result) cout << path << endl;
    return 0;
}
