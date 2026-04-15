#include <vector>
#include <cmath>
using namespace std;
// ============================================================
// Solution 1: Naive — walk up K steps one at a time — O(K) per query
// ============================================================
class Solution1 {
    vector<int> parent;
public:
    Solution1(int n, vector<int>& par) : parent(par) {}
    int kthAncestor(int node, int k) {
        while (k > 0 && node != -1) { node = parent[node]; k--; }
        return node; // O(K) per query — too slow for K up to N
    }
};

// ============================================================
// Solution 2: Binary Lifting — precompute 2^j ancestors — O(log K) per query
// ============================================================
class Solution2 {
    vector<vector<int>> up; // up[node][j] = 2^j-th ancestor
    int LOG;
public:
    Solution2(int n, vector<int>& parent) {
        LOG = log2(n) + 1;
        up.assign(n, vector<int>(LOG, -1));
        for (int i = 0; i < n; i++) up[i][0] = parent[i];
        for (int j = 1; j < LOG; j++)
            for (int i = 0; i < n; i++)
                if (up[i][j-1] != -1) up[i][j] = up[up[i][j-1]][j-1];
    }
    int kthAncestor(int node, int k) {
        for (int j = 0; j < LOG && node != -1; j++)
            if (k & (1 << j)) node = up[node][j];
        return node; // O(log K) per query!
    }
};
