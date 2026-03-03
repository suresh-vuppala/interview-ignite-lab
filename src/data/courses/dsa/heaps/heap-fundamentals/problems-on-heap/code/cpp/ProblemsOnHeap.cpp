#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class ProblemsOnHeap {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }
        
        auto cmp = [&count](int a, int b) {
            return count[a] > count[b];
        };
        priority_queue<int, vector<int>, decltype(cmp)> heap(cmp);
        
        for (auto& p : count) {
            heap.push(p.first);
            if (heap.size() > k) {
                heap.pop();
            }
        }
        
        vector<int> result;
        while (!heap.empty()) {
            result.push_back(heap.top());
            heap.pop();
        }
        return result;
    }
};
