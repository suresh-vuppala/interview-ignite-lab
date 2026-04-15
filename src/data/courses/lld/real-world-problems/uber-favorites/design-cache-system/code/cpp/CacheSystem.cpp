#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <mutex>
using namespace std;

// ========== LRU CACHE — HashMap + Doubly Linked List ==========
class LRUCache {
    int capacity;
    list<pair<int,int>> dll;                         // {key, value} — front=MRU, back=LRU
    unordered_map<int, list<pair<int,int>>::iterator> map; // key -> DLL iterator
    mutex mtx;
public:
    LRUCache(int capacity) : capacity(capacity) {}
    
    int get(int key) {
        lock_guard<mutex> lock(mtx);
        auto it = map.find(key);
        if (it == map.end()) return -1;
        dll.splice(dll.begin(), dll, it->second); // Move to front (MRU)
        return it->second->second;
    }
    
    void put(int key, int value) {
        lock_guard<mutex> lock(mtx);
        auto it = map.find(key);
        if (it != map.end()) {
            it->second->second = value;
            dll.splice(dll.begin(), dll, it->second);
            return;
        }
        if ((int)map.size() >= capacity) {
            int lruKey = dll.back().first;
            dll.pop_back();
            map.erase(lruKey);
        }
        dll.push_front({key, value});
        map[key] = dll.begin();
    }
};

// ========== LFU CACHE ==========
class LFUCache {
    int capacity, minFreq = 0;
    unordered_map<int, pair<int,int>> keyMap;           // key -> {value, freq}
    unordered_map<int, list<int>> freqMap;              // freq -> list of keys (LRU order)
    unordered_map<int, list<int>::iterator> keyIter;    // key -> iterator in freqMap list
    mutex mtx;
    
    void incrementFreq(int key) {
        int oldFreq = keyMap[key].second;
        keyMap[key].second++;
        freqMap[oldFreq].erase(keyIter[key]);
        if (freqMap[oldFreq].empty()) {
            freqMap.erase(oldFreq);
            if (minFreq == oldFreq) minFreq++;
        }
        freqMap[oldFreq + 1].push_front(key);
        keyIter[key] = freqMap[oldFreq + 1].begin();
    }
    
    void evict() {
        int evictKey = freqMap[minFreq].back();
        freqMap[minFreq].pop_back();
        if (freqMap[minFreq].empty()) freqMap.erase(minFreq);
        keyMap.erase(evictKey);
        keyIter.erase(evictKey);
    }
public:
    LFUCache(int capacity) : capacity(capacity) {}
    
    int get(int key) {
        lock_guard<mutex> lock(mtx);
        if (!keyMap.count(key)) return -1;
        incrementFreq(key);
        return keyMap[key].first;
    }
    
    void put(int key, int value) {
        lock_guard<mutex> lock(mtx);
        if (capacity == 0) return;
        if (keyMap.count(key)) {
            keyMap[key].first = value;
            incrementFreq(key);
            return;
        }
        if ((int)keyMap.size() >= capacity) evict();
        keyMap[key] = {value, 1};
        freqMap[1].push_front(key);
        keyIter[key] = freqMap[1].begin();
        minFreq = 1;
    }
};
