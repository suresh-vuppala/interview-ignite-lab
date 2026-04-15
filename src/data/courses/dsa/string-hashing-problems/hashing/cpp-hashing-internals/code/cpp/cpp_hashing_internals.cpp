#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;
// ============================================================
// Solution 1: std::map (red-black tree) — O(log N) per op
// ============================================================
#include <map>
class Solution1 {
public:
    void demo() {
        map<string, int> m; // Sorted keys, O(log N) ops
        m["apple"] = 1;
        m["banana"] = 2;
        // Ordered iteration, but slower than hash map
    }
};

// ============================================================
// Solution 2: std::unordered_map — O(1) average, O(N) worst case
// ============================================================
class Solution2 {
public:
    void demo() {
        unordered_map<string, int> m; // Hash table, O(1) average
        m.reserve(1024); // Pre-allocate to avoid rehashing
        m["apple"] = 1;
        m["banana"] = 2;
        // Custom hash for pairs:
        // struct PairHash { size_t operator()(pair<int,int> p) const {
        //     return hash<long long>()(((long long)p.first << 32) | p.second); }};
        // unordered_map<pair<int,int>, int, PairHash> pm;
    }
    // Collision handling: chaining (linked list per bucket)
    // Load factor: rehash when size/bucket_count > max_load_factor (default 1.0)
};
