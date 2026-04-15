#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: Simulation with priority queue — O(N * n)
// ============================================================
class Solution1 {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26] = {};
        for (char c : tasks) freq[c - 'A']++;
        priority_queue<int> pq;
        for (int f : freq) if (f) pq.push(f);
        int time = 0;
        while (!pq.empty()) {
            vector<int> temp;
            for (int i = 0; i <= n; i++) {
                if (!pq.empty()) { temp.push_back(pq.top() - 1); pq.pop(); }
                time++;
                if (pq.empty() && temp.back() <= 0) { // Check if remaining are all 0
                    bool allDone = true;
                    for (int t : temp) if (t > 0) allDone = false;
                    if (allDone) break;
                }
            }
            for (int t : temp) if (t > 0) pq.push(t);
        }
        return time;
    }
};

// ============================================================
// Solution 2: Math formula — O(N) Time, O(1) Space
// ============================================================
class Solution2 {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26] = {};
        for (char c : tasks) freq[c - 'A']++;
        int maxFreq = *max_element(freq, freq + 26);
        int maxCount = 0; // How many tasks have maxFreq
        for (int f : freq) if (f == maxFreq) maxCount++;
        // Formula: (maxFreq-1) * (n+1) + maxCount
        int result = (maxFreq - 1) * (n + 1) + maxCount;
        return max(result, (int)tasks.size()); // At least total tasks
    }
};
