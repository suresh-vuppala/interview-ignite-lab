// ===========================================================================
// DESIGN: Cache System (LRU + LFU) — Low Level Design
// Key: HashMap + DLL for O(1) LRU, HashMap + FreqMap for O(1) LFU
// ===========================================================================
// FR: get(key), put(key,value) with O(1), eviction on capacity
// PLANTUML: Cache<|..LRUCache(HashMap+DLL), Cache<|..LFUCache(HashMap+FreqMap)

#include <iostream>
#include <map>
#include <list>
#include <set>
#include <string>
using namespace std;

// ========== LRU CACHE — HashMap + Doubly Linked List ==========
// list: front=MRU, back=LRU
class LRUCache {
    int capacity;
    list<pair<int,int> > dll;  // {key, value}
    map<int, list<pair<int,int> >::iterator> mp;
public:
    LRUCache(int cap) : capacity(cap) {}

    int get(int key) {
        if (!mp.count(key)) return -1;
        // Move to front (MRU)
        dll.splice(dll.begin(), dll, mp[key]);
        return mp[key]->second;
    }

    void put(int key, int value) {
        if (mp.count(key)) {
            mp[key]->second = value;
            dll.splice(dll.begin(), dll, mp[key]);
            return;
        }
        if ((int)mp.size() >= capacity) {
            int lruKey = dll.back().first;
            dll.pop_back();
            mp.erase(lruKey);
        }
        dll.push_front(make_pair(key, value));
        mp[key] = dll.begin();
    }
};

// ========== LFU CACHE — HashMap + Frequency Map ==========
class LFUCache {
    int capacity, minFreq;
    map<int, pair<int,int> > keyMap;  // key -> {value, freq}
    map<int, list<int> > freqMap;     // freq -> list of keys (LRU order)
    map<int, list<int>::iterator> keyIter;  // key -> iterator in freqMap list

    void incrementFreq(int key) {
        int oldFreq = keyMap[key].second;
        keyMap[key].second++;
        freqMap[oldFreq].erase(keyIter[key]);
        if (freqMap[oldFreq].empty()) {
            freqMap.erase(oldFreq);
            if (minFreq == oldFreq) minFreq++;
        }
        freqMap[oldFreq+1].push_front(key);
        keyIter[key] = freqMap[oldFreq+1].begin();
    }

    void evict() {
        int evictKey = freqMap[minFreq].back();
        freqMap[minFreq].pop_back();
        if (freqMap[minFreq].empty()) freqMap.erase(minFreq);
        keyMap.erase(evictKey);
        keyIter.erase(evictKey);
    }
public:
    LFUCache(int cap) : capacity(cap), minFreq(0) {}

    int get(int key) {
        if (!keyMap.count(key)) return -1;
        incrementFreq(key);
        return keyMap[key].first;
    }

    void put(int key, int value) {
        if (capacity == 0) return;
        if (keyMap.count(key)) { keyMap[key].first = value; incrementFreq(key); return; }
        if ((int)keyMap.size() >= capacity) evict();
        keyMap[key] = make_pair(value, 1);
        freqMap[1].push_front(key);
        keyIter[key] = freqMap[1].begin();
        minFreq = 1;
    }
};

int main() {
    cout << "============================================\n  Cache System — LLD Demo\n============================================" << endl;

    // LRU Demo
    cout << "\n--- LRU Cache (cap=3) ---" << endl;
    LRUCache lru(3);
    lru.put(1, 10); lru.put(2, 20); lru.put(3, 30);
    cout << "  get(1): " << lru.get(1) << endl;  // 10 (moves 1 to front)
    lru.put(4, 40);  // Evicts key=2 (LRU)
    cout << "  get(2): " << lru.get(2) << " (evicted)" << endl;
    cout << "  get(3): " << lru.get(3) << endl;
    cout << "  get(4): " << lru.get(4) << endl;

    // LFU Demo
    cout << "\n--- LFU Cache (cap=3) ---" << endl;
    LFUCache lfu(3);
    lfu.put(1, 10); lfu.put(2, 20); lfu.put(3, 30);
    lfu.get(1); lfu.get(1);  // freq(1)=3
    lfu.get(2);              // freq(2)=2
    lfu.put(4, 40);          // Evicts key=3 (freq=1, least frequent)
    cout << "  get(3): " << lfu.get(3) << " (evicted - least frequent)" << endl;
    cout << "  get(1): " << lfu.get(1) << " (freq=4 now)" << endl;
    cout << "  get(4): " << lfu.get(4) << endl;

    cout << "\n=== Complete ===" << endl;
    return 0;
}
// SUMMARY:
// LRU: HashMap(O(1) lookup) + DLL(O(1) move-to-front) = O(1) get/put
// LFU: HashMap(key->val,freq) + FreqMap(freq->list) + minFreq tracker = O(1)
// PATTERNS: Strategy(LRU vs LFU), Composite data structure (two maps)
// PRACTICES: O(1) all ops, splice for DLL move, eviction on capacity
