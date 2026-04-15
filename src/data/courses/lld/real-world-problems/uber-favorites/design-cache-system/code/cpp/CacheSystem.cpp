#include <unordered_map>
#include <unordered_set>
#include <map>
#include <list>
#include <iostream>
#include <mutex>
using namespace std;

// ========== LRU CACHE — HashMap + Doubly Linked List ==========
class LRUCache {
    int capacity;
    list<pair<int,int>> dll; // front = MRU, back = LRU
    unordered_map<int, list<pair<int,int>>::iterator> cache;
public:
    LRUCache(int cap) : capacity(cap) {}

    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end()) return -1;
        dll.splice(dll.begin(), dll, it->second); // Move to front (MRU)
        return it->second->second;
    }

    void put(int key, int value) {
        auto it = cache.find(key);
        if (it != cache.end()) {
            it->second->second = value;
            dll.splice(dll.begin(), dll, it->second);
        } else {
            if ((int)cache.size() >= capacity) {
                int lruKey = dll.back().first;
                dll.pop_back();
                cache.erase(lruKey);
            }
            dll.emplace_front(key, value);
            cache[key] = dll.begin();
        }
    }
};

// ========== LFU CACHE ==========
class LFUCache {
    int capacity, minFreq = 0;
    unordered_map<int, pair<int,int>> keyMap; // key -> {value, freq}
    unordered_map<int, list<int>> freqMap;    // freq -> keys (LRU order)
    unordered_map<int, list<int>::iterator> keyIter; // key -> position in freqMap list
public:
    LFUCache(int cap) : capacity(cap) {}

    int get(int key) {
        auto it = keyMap.find(key);
        if (it == keyMap.end()) return -1;
        incrementFreq(key);
        return it->second.first;
    }

    void put(int key, int value) {
        if (capacity == 0) return;
        auto it = keyMap.find(key);
        if (it != keyMap.end()) {
            it->second.first = value;
            incrementFreq(key);
        } else {
            if ((int)keyMap.size() >= capacity) evict();
            keyMap[key] = {value, 1};
            freqMap[1].push_back(key);
            keyIter[key] = prev(freqMap[1].end());
            minFreq = 1;
        }
    }

private:
    void incrementFreq(int key) {
        int oldFreq = keyMap[key].second;
        keyMap[key].second++;
        freqMap[oldFreq].erase(keyIter[key]);
        if (freqMap[oldFreq].empty()) {
            freqMap.erase(oldFreq);
            if (minFreq == oldFreq) minFreq++;
        }
        freqMap[oldFreq + 1].push_back(key);
        keyIter[key] = prev(freqMap[oldFreq + 1].end());
    }

    void evict() {
        int evictKey = freqMap[minFreq].front();
        freqMap[minFreq].pop_front();
        if (freqMap[minFreq].empty()) freqMap.erase(minFreq);
        keyMap.erase(evictKey);
        keyIter.erase(evictKey);
    }
};
