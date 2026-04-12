// ============================================================
// LFU Cache
// ============================================================
#include <unordered_map>
#include <list>
using namespace std;

class LFUCache {
    int capacity, minFreq;
    unordered_map<int, pair<int,int>> keyVal;     // key → (value, freq)
    unordered_map<int, list<int>::iterator> keyIter; // key → iterator in freq list
    unordered_map<int, list<int>> freqList;        // freq → list of keys (LRU order)

    void touch(int key) {
        int freq = keyVal[key].second;
        freqList[freq].erase(keyIter[key]);
        if (freqList[freq].empty()) {
            freqList.erase(freq);
            if (minFreq == freq) minFreq++;
        }
        keyVal[key].second++;
        freqList[freq + 1].push_front(key);
        keyIter[key] = freqList[freq + 1].begin();
    }

public:
    LFUCache(int cap) : capacity(cap), minFreq(0) {}

    int get(int key) {
        if (!keyVal.count(key)) return -1;
        touch(key);
        return keyVal[key].first;
    }

    void put(int key, int value) {
        if (capacity <= 0) return;
        if (keyVal.count(key)) {
            keyVal[key].first = value;
            touch(key);
            return;
        }
        if ((int)keyVal.size() >= capacity) {
            int evict = freqList[minFreq].back();
            freqList[minFreq].pop_back();
            if (freqList[minFreq].empty()) freqList.erase(minFreq);
            keyVal.erase(evict);
            keyIter.erase(evict);
        }
        keyVal[key] = {value, 1};
        freqList[1].push_front(key);
        keyIter[key] = freqList[1].begin();
        minFreq = 1;
    }
};
