import java.util.*;
public class LfuCache {
    Map<Integer,Integer> keyToVal, keyToFreq; Map<Integer,LinkedHashSet<Integer>> freqToKeys; int cap, minFreq;
    public LfuCache(int capacity) { cap=capacity; keyToVal=new HashMap<>(); keyToFreq=new HashMap<>(); freqToKeys=new HashMap<>(); minFreq=0; }
    void updateFreq(int key) { int freq=keyToFreq.get(key); freqToKeys.get(freq).remove(key); if(freqToKeys.get(freq).isEmpty()) { freqToKeys.remove(freq); if(minFreq==freq) minFreq++; } keyToFreq.put(key,freq+1); freqToKeys.computeIfAbsent(freq+1,k->new LinkedHashSet<>()).add(key); }
    public int get(int key) { if(!keyToVal.containsKey(key)) return -1; updateFreq(key); return keyToVal.get(key); }
    public void put(int key, int val) { if(cap<=0) return; if(keyToVal.containsKey(key)) { keyToVal.put(key,val); updateFreq(key); return; } if(keyToVal.size()>=cap) { int evict=freqToKeys.get(minFreq).iterator().next(); freqToKeys.get(minFreq).remove(evict); keyToVal.remove(evict); keyToFreq.remove(evict); } keyToVal.put(key,val); keyToFreq.put(key,1); freqToKeys.computeIfAbsent(1,k->new LinkedHashSet<>()).add(key); minFreq=1; }
    public static void main(String[] a) { LfuCache c=new LfuCache(2); c.put(1,1); c.put(2,2); System.out.println(c.get(1)); c.put(3,3); System.out.println(c.get(2)); }
}