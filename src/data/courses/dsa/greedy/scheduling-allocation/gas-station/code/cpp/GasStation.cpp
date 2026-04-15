#include <vector>
using namespace std;
// ============================================================
// Solution 1: Brute Force — try starting from each station — O(N²)
// ============================================================
class Solution1 {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for (int start = 0; start < n; start++) {
            int tank = 0; bool valid = true;
            for (int j = 0; j < n; j++) {
                int idx = (start + j) % n;
                tank += gas[idx] - cost[idx];
                if (tank < 0) { valid = false; break; }
            }
            if (valid) return start;
        }
        return -1;
    }
};

// ============================================================
// Solution 2: Greedy — single pass — O(N) Time, O(1) Space
// ============================================================
class Solution2 {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0, tank = 0, start = 0;
        for (int i = 0; i < (int)gas.size(); i++) {
            int diff = gas[i] - cost[i];
            total += diff;
            tank += diff;
            if (tank < 0) { start = i + 1; tank = 0; } // Reset start
        }
        return total >= 0 ? start : -1;
    }
};
