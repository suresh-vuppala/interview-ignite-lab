// Java HashMap internals — C++ equivalent demonstration
#include <unordered_map>
#include <vector>
using namespace std;
// ============================================================
// Solution 1: Chaining with linked list (Java 7 style)
// ============================================================
class Solution1 {
    struct Node { int key, val; Node* next; Node(int k,int v):key(k),val(v),next(nullptr){} };
    vector<Node*> buckets;
    int sz = 0, cap;
public:
    Solution1(int capacity = 16) : cap(capacity), buckets(capacity, nullptr) {}
    void put(int key, int val) {
        int idx = key % cap;
        Node* cur = buckets[idx];
        while (cur) { if (cur->key == key) { cur->val = val; return; } cur = cur->next; }
        Node* n = new Node(key, val); n->next = buckets[idx]; buckets[idx] = n; sz++;
    }
    int get(int key) {
        Node* cur = buckets[key % cap];
        while (cur) { if (cur->key == key) return cur->val; cur = cur->next; }
        return -1;
    }
};

// ============================================================
// Solution 2: Open addressing with linear probing (alternative)
// ============================================================
class Solution2 {
    vector<pair<int,int>> table; // {key, val}, -1 = empty
    vector<bool> occupied;
    int cap;
public:
    Solution2(int capacity = 16) : cap(capacity), table(capacity, {-1,-1}), occupied(capacity, false) {}
    void put(int key, int val) {
        int idx = key % cap;
        while (occupied[idx] && table[idx].first != key) idx = (idx + 1) % cap; // Linear probe
        table[idx] = {key, val}; occupied[idx] = true;
    }
    int get(int key) {
        int idx = key % cap;
        while (occupied[idx]) { if (table[idx].first == key) return table[idx].second; idx = (idx + 1) % cap; }
        return -1;
    }
};
