from collections import defaultdict, OrderedDict
class LFUCache:
    def __init__(self, capacity): self.cap=capacity; self.keyToVal={}; self.keyToFreq={}; self.freqToKeys=defaultdict(OrderedDict); self.minFreq=0
    def update_freq(self, key): freq=self.keyToFreq[key]; del self.freqToKeys[freq][key]; [self.freqToKeys.pop(freq) or (self.minFreq:=self.minFreq+1) for _ in [1] if not self.freqToKeys[freq] and self.minFreq==freq]; self.keyToFreq[key]=freq+1; self.freqToKeys[freq+1][key]=None
    def get(self, key):
        if key not in self.keyToVal: return -1
        self.update_freq(key); return self.keyToVal[key]
    def put(self, key, val):
        if self.cap<=0: return
        if key in self.keyToVal: self.keyToVal[key]=val; self.update_freq(key); return
        if len(self.keyToVal)>=self.cap: evict=next(iter(self.freqToKeys[self.minFreq])); del self.freqToKeys[self.minFreq][evict]; del self.keyToVal[evict]; del self.keyToFreq[evict]
        self.keyToVal[key]=val; self.keyToFreq[key]=1; self.freqToKeys[1][key]=None; self.minFreq=1
if __name__=="__main__": c=LFUCache(2); c.put(1,1); c.put(2,2); print(c.get(1)); c.put(3,3); print(c.get(2))