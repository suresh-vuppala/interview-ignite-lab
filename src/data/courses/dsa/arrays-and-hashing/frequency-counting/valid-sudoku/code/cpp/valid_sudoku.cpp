// ============================================================
// Valid Sudoku
// ============================================================

#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

// ============================================================
// Solution 1: Three Separate Passes
// Time: O(1) | Space: O(1) — board is always 9×9
// ============================================================
class Solution1 {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Check rows
        for (int i = 0; i < 9; i++) {
            unordered_set<char> seen;
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                if (seen.count(board[i][j])) return false;
                seen.insert(board[i][j]);
            }
        }

        // Check columns
        for (int j = 0; j < 9; j++) {
            unordered_set<char> seen;
            for (int i = 0; i < 9; i++) {
                if (board[i][j] == '.') continue;
                if (seen.count(board[i][j])) return false;
                seen.insert(board[i][j]);
            }
        }

        // Check 3×3 boxes
        for (int bi = 0; bi < 3; bi++) {
            for (int bj = 0; bj < 3; bj++) {
                unordered_set<char> seen;
                for (int i = bi*3; i < bi*3+3; i++) {
                    for (int j = bj*3; j < bj*3+3; j++) {
                        if (board[i][j] == '.') continue;
                        if (seen.count(board[i][j])) return false;
                        seen.insert(board[i][j]);
                    }
                }
            }
        }

        return true;
    }
};

// ============================================================
// Solution 2: Single Pass with Encoded Set (Optimal)
// Time: O(1) | Space: O(1)
// ============================================================
class Solution2 {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> seen;

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;

                char d = board[i][j];

                // Encode three membership constraints as strings
                string row = string(1, d) + " row " + to_string(i);
                string col = string(1, d) + " col " + to_string(j);
                string box = string(1, d) + " box " + to_string(i/3) + to_string(j/3);

                // If any already seen → duplicate → invalid
                if (seen.count(row) || seen.count(col) || seen.count(box))
                    return false;

                seen.insert(row);
                seen.insert(col);
                seen.insert(box);
            }
        }

        return true;
    }
};
