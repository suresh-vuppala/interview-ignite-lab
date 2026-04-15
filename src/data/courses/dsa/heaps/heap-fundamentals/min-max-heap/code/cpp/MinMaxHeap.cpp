#include <vector>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: Unsorted array — O(1) insert, O(N) extract
// ============================================================
class Solution1 {
    vector<int> data;
public:
    void insert(int val) { data.push_back(val); } // O(1)
    int extractMin() {
        auto it = min_element(data.begin(), data.end()); // O(N) scan!
        int val = *it; data.erase(it); return val;
    }
    int extractMax() {
        auto it = max_element(data.begin(), data.end());
        int val = *it; data.erase(it); return val;
    }
};

// ============================================================
// Solution 2: Binary heap — O(log N) insert and extract
// ============================================================
class Solution2 {
    vector<int> heap;
    void siftUp(int i) { while(i>0){int p=(i-1)/2;if(heap[p]>heap[i]){swap(heap[p],heap[i]);i=p;}else break;} }
    void siftDown(int i) {
        int n=heap.size();
        while(2*i+1<n){int s=2*i+1;if(s+1<n&&heap[s+1]<heap[s])s++;if(heap[i]<=heap[s])break;swap(heap[i],heap[s]);i=s;}
    }
public:
    void insert(int val) { heap.push_back(val); siftUp(heap.size()-1); }
    int extractMin() { int val=heap[0]; heap[0]=heap.back(); heap.pop_back(); if(!heap.empty())siftDown(0); return val; }
    int peekMin() { return heap[0]; }
};
