#include <vector>
#include <string>
using namespace std;

void backtrack(vector<vector<int>>& maze, int i, int j, string path, vector<vector<bool>>& visited, vector<string>& result) {
    int n = maze.size();
    if (i == n-1 && j == n-1) {
        result.push_back(path);
        return;
    }
    visited[i][j] = true;
    if (i+1 < n && maze[i+1][j] == 1 && !visited[i+1][j])
        backtrack(maze, i+1, j, path+"D", visited, result);
    if (j-1 >= 0 && maze[i][j-1] == 1 && !visited[i][j-1])
        backtrack(maze, i, j-1, path+"L", visited, result);
    if (j+1 < n && maze[i][j+1] == 1 && !visited[i][j+1])
        backtrack(maze, i, j+1, path+"R", visited, result);
    if (i-1 >= 0 && maze[i-1][j] == 1 && !visited[i-1][j])
        backtrack(maze, i-1, j, path+"U", visited, result);
    visited[i][j] = false;
}

vector<string> findPath(vector<vector<int>>& maze) {
    vector<string> result;
    if (maze[0][0] == 0) return result;
    int n = maze.size();
    vector<vector<bool>> visited(n, vector<bool>(n));
    backtrack(maze, 0, 0, "", visited, result);
    return result;
}