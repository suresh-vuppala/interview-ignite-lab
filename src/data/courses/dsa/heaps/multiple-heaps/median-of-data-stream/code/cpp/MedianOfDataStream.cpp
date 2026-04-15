#include <queue>
using namespace std;
// ============================================================
// Solution 1: Sorted array — O(N) insert, O(1) median
// ============================================================
#include <vector>
#include <algorithm>
class Solution1 {
    vector<int> data;
public:
    void addNum(int num) {
        auto it = lower_bound(data.begin(), data.end(), num);
        data.insert(it, num); // O(N) shift
    }
    double findMedian() {
        int n = data.size();
        if (n % 2) return data[n/2];
        return (data[n/2-1] + data[n/2]) / 2.0;
    }
};

// ============================================================
// Solution 2: Two heaps — max-heap (left) + min-heap (right) — O(log N) insert
// ============================================================
class Solution2 {
    priority_queue<int> left;                            // Max-heap: smaller half
    priority_queue<int, vector<int>, greater<>> right;   // Min-heap: larger half
public:
    void addNum(int num) {
        left.push(num);
        right.push(left.top()); left.pop(); // Balance: ensure left.top <= right.top
        if (left.size() < right.size()) { left.push(right.top()); right.pop(); }
    }
    double findMedian() {
        if (left.size() > right.size()) return left.top();
        return (left.top() + right.top()) / 2.0;
    }
};
