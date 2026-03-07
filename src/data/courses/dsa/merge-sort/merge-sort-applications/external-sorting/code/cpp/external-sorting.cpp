// Time: O(N log N), Space: O(M) where M is chunk size

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Element {
    int value, chunkIdx, elemIdx;
    bool operator>(const Element& other) const {
        return value > other.value;
    }
};

vector<int> externalSort(vector<int>& data, int chunkSize) {
    vector<vector<int>> chunks;
    
    // Phase 1: Create sorted chunks
    for (int i = 0; i < data.size(); i += chunkSize) {
        vector<int> chunk;
        for (int j = i; j < min(i + chunkSize, (int)data.size()); j++) {
            chunk.push_back(data[j]);
        }
        sort(chunk.begin(), chunk.end());
        chunks.push_back(chunk);
    }
    
    // Phase 2: K-way merge
    vector<int> result;
    priority_queue<Element, vector<Element>, greater<Element>> heap;
    
    for (int i = 0; i < chunks.size(); i++) {
        if (!chunks[i].empty()) {
            heap.push({chunks[i][0], i, 0});
        }
    }
    
    while (!heap.empty()) {
        Element e = heap.top();
        heap.pop();
        result.push_back(e.value);
        
        if (e.elemIdx + 1 < chunks[e.chunkIdx].size()) {
            int nextVal = chunks[e.chunkIdx][e.elemIdx + 1];
            heap.push({nextVal, e.chunkIdx, e.elemIdx + 1});
        }
    }
    
    return result;
}

int main() {
    vector<int> data = {64, 34, 25, 12, 22, 11, 90, 88, 45, 50, 33, 17};
    vector<int> sorted = externalSort(data, 3);
    for (int num : sorted) cout << num << " ";
    return 0;
}
