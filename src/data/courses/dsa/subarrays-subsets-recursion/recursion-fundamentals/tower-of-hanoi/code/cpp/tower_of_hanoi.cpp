#include <vector>
#include <string>
using namespace std;
// ============================================================
// Solution 1: Recursive — the only approach, inherently O(2^N - 1) moves
// ============================================================
class Solution1 {
    vector<string> moves;
    void solve(int n, char from, char to, char aux) {
        if (n == 0) return;
        solve(n - 1, from, aux, to);          // Move n-1 disks to aux
        moves.push_back(string(1,from) + " -> " + string(1,to)); // Move nth disk
        solve(n - 1, aux, to, from);           // Move n-1 disks from aux to target
    }
public:
    vector<string> hanoi(int n) { moves.clear(); solve(n, 'A', 'C', 'B'); return moves; }
};

// ============================================================
// Solution 2: Iterative — simulate using stack states — O(2^N - 1)
// ============================================================
#include <stack>
class Solution2 {
public:
    vector<string> hanoi(int n) {
        vector<string> moves;
        // For N disks: if N is even, swap target and auxiliary
        stack<int> pegs[3]; // A=0, B=1, C=2
        for (int i = n; i >= 1; i--) pegs[0].push(i);
        int total = (1 << n) - 1;
        // Even: cycle is A->B->C; Odd: cycle is A->C->B
        int from, to;
        for (int i = 1; i <= total; i++) {
            if (i % 3 == 1) { from = 0; to = (n % 2 == 0) ? 1 : 2; }
            else if (i % 3 == 2) { from = 0; to = (n % 2 == 0) ? 2 : 1; }
            else { from = 1; to = 2; }
            // Legal move between pegs[from] and pegs[to]
            if (pegs[from].empty() || (!pegs[to].empty() && pegs[to].top() < pegs[from].top()))
                swap(from, to);
            pegs[to].push(pegs[from].top()); pegs[from].pop();
            moves.push_back(to_string(from) + " -> " + to_string(to));
        }
        return moves;
    }
};
