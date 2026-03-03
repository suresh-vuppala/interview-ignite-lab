#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class LFUCache { unordered_map<int,int> keyToVal, keyToFreq; unordered_map<int,unordered_set<int>> freqToKeys; int cap, minFreq;
void updateFreq(int key) { int freq=keyToFreq[key]; freqToKeys[freq].erase(key); if(freqToKeys[freq].empty()) { freqToKeys.erase(freq); if(minFreq==freq) minFreq++; } keyToFreq[key]=freq+1; freqToKeys[freq+1].insert(key); }
public: LFUCache(int capacity):cap(capacity),minFreq(0) {}
int get(int key) { if(keyToVal.find(key)==keyToVal.end()) return -1; updateFreq(key); return keyToVal[key]; }
void put(int key, int val) { if(cap<=0) return; if(keyToVal.find(key)!=keyToVal.end()) { keyToVal[key]=val; updateFreq(key); return; } if(keyToVal.size()>=cap) { int evict=*freqToKeys[minFreq].begin(); freqToKeys[minFreq].erase(evict); keyToVal.erase(evict); keyToFreq.erase(evict); } keyToVal[key]=val; keyToFreq[key]=1; freqToKeys[1].insert(key); minFreq=1; }};
int main() { LFUCache c(2); c.put(1,1); c.put(2,2); cout<<c.get(1)<<endl; c.put(3,3); cout<<c.get(2)<<endl; return 0; }