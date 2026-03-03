#include <vector>
#include <algorithm>
using namespace std;

class MinMaxHeap {
    vector<int> heap;
    
    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }
    
    void bubbleUp(int i) {
        while (i > 0 && heap[i] > heap[parent(i)]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }
    
    void bubbleDown(int i) {
        int maxIndex = i;
        int l = left(i);
        int r = right(i);
        
        if (l < heap.size() && heap[l] > heap[maxIndex])
            maxIndex = l;
        if (r < heap.size() && heap[r] > heap[maxIndex])
            maxIndex = r;
        
        if (i != maxIndex) {
            swap(heap[i], heap[maxIndex]);
            bubbleDown(maxIndex);
        }
    }
    
public:
    void insert(int val) {
        heap.push_back(val);
        bubbleUp(heap.size() - 1);
    }
    
    int extractMax() {
        int max = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) bubbleDown(0);
        return max;
    }
};
