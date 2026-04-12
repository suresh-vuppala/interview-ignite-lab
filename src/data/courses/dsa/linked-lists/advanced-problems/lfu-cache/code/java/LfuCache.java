// ============================================================
// LFU Cache
// ============================================================
import java.util.*;
class LFUCache {
    int cap, minFreq;
    Map<Integer,int[]> keyVal = new HashMap<>(); // key->[val,freq]
    Map<Integer,LinkedHashSet<Integer>> freqKeys = new HashMap<>();
    public LFUCache(int c){cap=c;}
    public int get(int key){
        if(!keyVal.containsKey(key))return -1;
        touch(key);return keyVal.get(key)[0];
    }
    public void put(int key,int val){
        if(cap<=0)return;
        if(keyVal.containsKey(key)){keyVal.get(key)[0]=val;touch(key);return;}
        if(keyVal.size()>=cap){
            int evict=freqKeys.get(minFreq).iterator().next();
            freqKeys.get(minFreq).remove(evict);keyVal.remove(evict);
        }
        keyVal.put(key,new int[]{val,1});
        freqKeys.computeIfAbsent(1,k->new LinkedHashSet<>()).add(key);
        minFreq=1;
    }
    void touch(int key){
        int f=keyVal.get(key)[1];freqKeys.get(f).remove(key);
        if(freqKeys.get(f).isEmpty()&&minFreq==f)minFreq++;
        keyVal.get(key)[1]++;
        freqKeys.computeIfAbsent(f+1,k->new LinkedHashSet<>()).add(key);
    }
}
