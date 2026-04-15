#include <unordered_map>
#include <list>
using namespace std;

// ============================================================
// Solution 1: Linear scan for minimum frequency — O(N) per operation
// ============================================================
#include <vector>
class Solution1 {
    struct Entry { int key,val,freq; };
    vector<Entry> cache; int cap;
public:
    Solution1(int capacity):cap(capacity){}
    int get(int key) {
        for(auto&e:cache)if(e.key==key){e.freq++;return e.val;}return -1;
    }
    void put(int key,int value) {
        if(cap<=0)return;
        for(auto&e:cache){if(e.key==key){e.val=value;e.freq++;return;}}
        if((int)cache.size()>=cap){
            int minF=1e9,idx=0;for(int i=0;i<(int)cache.size();i++)if(cache[i].freq<minF){minF=cache[i].freq;idx=i;}
            cache.erase(cache.begin()+idx);
        }
        cache.push_back({key,value,1});
    }
};

// ============================================================
// Solution 2: Two HashMaps + DLL per frequency — O(1) per operation
// ============================================================
class Solution2 {
    int cap, minFreq=0;
    unordered_map<int,pair<int,int>> keyMap; // key → {val, freq}
    unordered_map<int,list<int>> freqMap;    // freq → list of keys (LRU order)
    unordered_map<int,list<int>::iterator> iterMap; // key → iterator in freq list
public:
    Solution2(int capacity):cap(capacity){}
    int get(int key){
        if(!keyMap.count(key))return -1;
        auto&[val,freq]=keyMap[key];
        freqMap[freq].erase(iterMap[key]);if(freqMap[freq].empty()){freqMap.erase(freq);if(minFreq==freq)minFreq++;}
        freq++;freqMap[freq].push_back(key);iterMap[key]=prev(freqMap[freq].end());
        return val;
    }
    void put(int key,int value){
        if(cap<=0)return;
        if(keyMap.count(key)){keyMap[key].first=value;get(key);return;}
        if((int)keyMap.size()>=cap){int evict=freqMap[minFreq].front();freqMap[minFreq].pop_front();if(freqMap[minFreq].empty())freqMap.erase(minFreq);keyMap.erase(evict);iterMap.erase(evict);}
        keyMap[key]={value,1};freqMap[1].push_back(key);iterMap[key]=prev(freqMap[1].end());minFreq=1;
    }
};
