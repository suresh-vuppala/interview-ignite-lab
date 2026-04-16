// ===========================================================================
// DESIGN: Hit Counter (Concurrent) — Low Level Design
// ===========================================================================
// Single-file C++ | Pattern: Circular Buffer (Ring Buffer)
// Key: O(1) hit, O(W) getHits, fixed memory
// ===========================================================================

// 1. FR: hit(timestamp) records event, getHits(timestamp) returns count in last 300s
// 2. CONSTRAINTS: Window=300s, timestamps monotonic, thread-safe
// 3. RELATIONSHIPS: HitCounter *-- circular arrays (timestamps[] + hits[])
// 4. PLANTUML:
// @startuml
// class HitCounter { -timestamps[300] -hits[300] +hit(ts) +getHits(ts) }
// class HitCounterQueue { -queue:deque +hit(ts) +getHits(ts) }
// @enduml

#include <iostream>
#include <string>
#include <vector>
#include <deque>
using namespace std;

// Approach 1: Circular Array — O(1) hit, O(300) getHits, O(300) space
class HitCounter {
    static const int WINDOW = 300;
    int timestamps[300];
    int hits[300];
public:
    HitCounter() {
        for (int i = 0; i < WINDOW; i++) { timestamps[i] = 0; hits[i] = 0; }
    }

    // O(1) — record a hit
    void hit(int timestamp) {
        int idx = timestamp % WINDOW;
        if (timestamps[idx] != timestamp) {
            timestamps[idx] = timestamp;  // New second — reset
            hits[idx] = 1;
        } else {
            hits[idx]++;  // Same second — increment
        }
    }

    // O(300) — count hits in last 300 seconds
    int getHits(int timestamp) const {
        int total = 0;
        for (int i = 0; i < WINDOW; i++) {
            if (timestamp - timestamps[i] < WINDOW) {
                total += hits[i];
            }
        }
        return total;
    }
};

// Approach 2: Queue-based — O(1) hit, O(n) getHits, O(n) space
class HitCounterQueue {
    deque<int> queue;
public:
    void hit(int timestamp) { queue.push_back(timestamp); }

    int getHits(int timestamp) {
        while (!queue.empty() && timestamp - queue.front() >= 300)
            queue.pop_front();
        return queue.size();
    }
};

// ===========================================================================
// MAIN
// ===========================================================================
int main() {
    cout << "============================================" << endl;
    cout << "  Hit Counter — LLD Demo" << endl;
    cout << "============================================" << endl;

    HitCounter counter;

    // Simulate hits
    cout << "\n--- Recording hits ---" << endl;
    counter.hit(1);
    counter.hit(2);
    counter.hit(3);
    counter.hit(3);  // 2 hits at t=3
    counter.hit(100);
    counter.hit(200);
    counter.hit(300);

    cout << "  Hits at t=1,2,3,3,100,200,300" << endl;
    cout << "  getHits(300): " << counter.getHits(300) << " (all within window)" << endl;
    cout << "  getHits(301): " << counter.getHits(301) << " (t=1 expired)" << endl;
    cout << "  getHits(302): " << counter.getHits(302) << " (t=1,2 expired)" << endl;
    cout << "  getHits(600): " << counter.getHits(600) << " (only t=300 remains)" << endl;
    cout << "  getHits(601): " << counter.getHits(601) << " (all expired)" << endl;

    // Queue-based comparison
    cout << "\n--- Queue-based approach ---" << endl;
    HitCounterQueue qc;
    qc.hit(1); qc.hit(2); qc.hit(3); qc.hit(3); qc.hit(100); qc.hit(200); qc.hit(300);
    cout << "  getHits(300): " << qc.getHits(300) << endl;
    cout << "  getHits(301): " << qc.getHits(301) << endl;

    cout << "\n=== Complete ===" << endl;
    return 0;
}

// SUMMARY:
// EXECUTION FLOW: main() -> counter.hit(ts) -> idx=ts%300 -> reset or increment
//   -> counter.getHits(ts) -> scan 300 buckets -> sum non-expired
// DESIGN PATTERNS: Circular Buffer (space-efficient ring), Two approaches shown
// CLASS TABLE: HitCounter(circular array O(1)/O(W)) | HitCounterQueue(deque O(1)/O(n))
// BEST PRACTICES: O(1) hit (interview key), fixed memory O(W), bucket-based
