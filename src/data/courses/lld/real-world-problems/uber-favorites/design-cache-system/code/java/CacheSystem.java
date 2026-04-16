// DESIGN: Cache System (LRU+LFU) — LLD (Java)
import java.util.*;
class LRUCache {
    int capacity; LinkedHashMap<Integer,Integer> map;
    LRUCache(int cap){capacity=cap;map=new LinkedHashMap<>(cap,0.75f,true){
        protected boolean removeEldestEntry(Map.Entry e){return size()>capacity;}
    };}
    synchronized int get(int key){return map.getOrDefault(key,-1);}
    synchronized void put(int key,int val){map.put(key,val);}
}
class LFUCache {
    int capacity,minFreq;
    Map<Integer,int[]> keyMap=new HashMap<>(); // key->{val,freq}
    Map<Integer,LinkedHashSet<Integer>> freqMap=new HashMap<>();
    LFUCache(int cap){capacity=cap;}
    int get(int key){
        if(!keyMap.containsKey(key))return -1;
        int[] d=keyMap.get(key); incrementFreq(key,d[1]); d[1]++; return d[0];
    }
    void put(int key,int val){
        if(capacity==0)return;
        if(keyMap.containsKey(key)){int[] d=keyMap.get(key);d[0]=val;incrementFreq(key,d[1]);d[1]++;return;}
        if(keyMap.size()>=capacity) evict();
        keyMap.put(key,new int[]{val,1}); freqMap.computeIfAbsent(1,k->new LinkedHashSet<>()).add(key); minFreq=1;
    }
    void incrementFreq(int key,int oldF){
        freqMap.get(oldF).remove(key);if(freqMap.get(oldF).isEmpty()){freqMap.remove(oldF);if(minFreq==oldF)minFreq++;}
        freqMap.computeIfAbsent(oldF+1,k->new LinkedHashSet<>()).add(key);
    }
    void evict(){int ek=freqMap.get(minFreq).iterator().next();freqMap.get(minFreq).remove(ek);
        if(freqMap.get(minFreq).isEmpty())freqMap.remove(minFreq);keyMap.remove(ek);}
}
public class CacheSystem {
    public static void main(String[] args) {
        System.out.println("=== Cache System — Java ===");
        LRUCache lru=new LRUCache(3);
        lru.put(1,10);lru.put(2,20);lru.put(3,30);
        System.out.println("LRU get(1): "+lru.get(1));
        lru.put(4,40); // evicts 2
        System.out.println("LRU get(2): "+lru.get(2)+" (evicted)");
        System.out.println("LRU get(4): "+lru.get(4));
        LFUCache lfu=new LFUCache(3);
        lfu.put(1,10);lfu.put(2,20);lfu.put(3,30);
        lfu.get(1);lfu.get(1);lfu.get(2);
        lfu.put(4,40); // evicts 3 (freq=1)
        System.out.println("LFU get(3): "+lfu.get(3)+" (evicted)");
        System.out.println("LFU get(1): "+lfu.get(1));
        System.out.println("=== Complete ===");
    }
}
// SUMMARY: LRU(LinkedHashMap accessOrder), LFU(HashMap+FreqMap+minFreq)
