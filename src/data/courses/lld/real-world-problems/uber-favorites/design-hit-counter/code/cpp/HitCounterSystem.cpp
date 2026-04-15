#include <vector>
#include <atomic>
#include <mutex>
#include <deque>
#include <iostream>
using namespace std;

// ========== CIRCULAR ARRAY APPROACH ==========
class HitCounter {
    static constexpr int WINDOW = 300;
    int timestamps[300] = {};
    atomic<int> hits[300] = {};
    mutex mtx;
public:
    void hit(int timestamp) {
        int idx = timestamp % WINDOW;
        lock_guard<mutex> lock(mtx);
        if (timestamps[idx] != timestamp) {
            timestamps[idx] = timestamp;
            hits[idx].store(1);
        } else {
            hits[idx].fetch_add(1);
        }
    }
    int getHits(int timestamp) const {
        int total = 0;
        for (int i = 0; i < WINDOW; i++)
            if (timestamp - timestamps[i] < WINDOW)
                total += hits[i].load();
        return total;
    }
};

// ========== QUEUE-BASED APPROACH ==========
class HitCounterQueue {
    deque<int> queue;
    mutex mtx;
public:
    void hit(int timestamp) {
        lock_guard<mutex> lock(mtx);
        queue.push_back(timestamp);
    }
    int getHits(int timestamp) {
        lock_guard<mutex> lock(mtx);
        while (!queue.empty() && timestamp - queue.front() >= 300)
            queue.pop_front();
        return queue.size();
    }
};
