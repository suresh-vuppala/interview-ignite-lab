// Cache System — LRU + LFU with Strategy
import java.util.*;

// ========== CACHE INTERFACE ==========
interface Cache<K, V> {
    V get(K key);
    void put(K key, V value);
    int size();
}

// ========== LRU CACHE — O(1) with LinkedHashMap ==========
class LRUCache<K, V> implements Cache<K, V> {
    private final int capacity;
    private final LinkedHashMap<K, V> map;
    
    public LRUCache(int capacity) {
        this.capacity = capacity;
        this.map = new LinkedHashMap<>(capacity, 0.75f, true) { // accessOrder=true
            @Override
            protected boolean removeEldestEntry(Map.Entry<K, V> eldest) {
                return size() > capacity; // Auto-evict LRU when full
            }
        };
    }
    
    public synchronized V get(K key) { return map.getOrDefault(key, null); }
    public synchronized void put(K key, V value) { map.put(key, value); }
    public int size() { return map.size(); }
}

// ========== LRU CACHE — Manual DLL Implementation ==========
class LRUCacheManual {
    private int capacity;
    private Map<Integer, DLLNode> map = new HashMap<>();
    private DLLNode head, tail; // Dummy sentinels
    
    static class DLLNode {
        int key, value;
        DLLNode prev, next;
        DLLNode(int k, int v) { key = k; value = v; }
    }
    
    public LRUCacheManual(int capacity) {
        this.capacity = capacity;
        head = new DLLNode(0, 0);
        tail = new DLLNode(0, 0);
        head.next = tail;
        tail.prev = head;
    }
    
    public int get(int key) {
        DLLNode node = map.get(key);
        if (node == null) return -1;
        moveToHead(node); // Mark as recently used
        return node.value;
    }
    
    public void put(int key, int value) {
        DLLNode node = map.get(key);
        if (node != null) {
            node.value = value;
            moveToHead(node);
        } else {
            DLLNode newNode = new DLLNode(key, value);
            map.put(key, newNode);
            addToHead(newNode);
            if (map.size() > capacity) {
                DLLNode lru = tail.prev;
                removeNode(lru);
                map.remove(lru.key);
            }
        }
    }
    
    private void addToHead(DLLNode node) {
        node.next = head.next;
        node.prev = head;
        head.next.prev = node;
        head.next = node;
    }
    
    private void removeNode(DLLNode node) {
        node.prev.next = node.next;
        node.next.prev = node.prev;
    }
    
    private void moveToHead(DLLNode node) {
        removeNode(node);
        addToHead(node);
    }
}

// ========== LFU CACHE ==========
class LFUCache {
    private int capacity, minFreq;
    private Map<Integer, int[]> keyMap; // key → [value, freq]
    private Map<Integer, LinkedHashSet<Integer>> freqMap; // freq → keys (insertion order)
    
    public LFUCache(int capacity) {
        this.capacity = capacity;
        keyMap = new HashMap<>();
        freqMap = new HashMap<>();
    }
    
    public int get(int key) {
        if (!keyMap.containsKey(key)) return -1;
        int[] data = keyMap.get(key);
        incrementFreq(key, data[1]);
        data[1]++;
        return data[0];
    }
    
    public void put(int key, int value) {
        if (capacity == 0) return;
        if (keyMap.containsKey(key)) {
            int[] data = keyMap.get(key);
            data[0] = value;
            incrementFreq(key, data[1]);
            data[1]++;
        } else {
            if (keyMap.size() >= capacity) evict();
            keyMap.put(key, new int[]{value, 1});
            freqMap.computeIfAbsent(1, k -> new LinkedHashSet<>()).add(key);
            minFreq = 1;
        }
    }
    
    private void incrementFreq(int key, int oldFreq) {
        freqMap.get(oldFreq).remove(key);
        if (freqMap.get(oldFreq).isEmpty()) {
            freqMap.remove(oldFreq);
            if (minFreq == oldFreq) minFreq++;
        }
        freqMap.computeIfAbsent(oldFreq + 1, k -> new LinkedHashSet<>()).add(key);
    }
    
    private void evict() {
        LinkedHashSet<Integer> keys = freqMap.get(minFreq);
        int evictKey = keys.iterator().next(); // Least recently used among least frequent
        keys.remove(evictKey);
        if (keys.isEmpty()) freqMap.remove(minFreq);
        keyMap.remove(evictKey);
    }
}
