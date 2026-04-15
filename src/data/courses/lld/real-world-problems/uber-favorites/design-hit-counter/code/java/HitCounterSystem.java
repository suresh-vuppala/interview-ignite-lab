// Hit Counter — Thread-safe Circular Array
import java.util.concurrent.atomic.*;

class HitCounter {
    private static final int WINDOW = 300; // 5 minutes
    private final int[] timestamps;
    private final AtomicIntegerArray hits;
    
    public HitCounter() {
        timestamps = new int[WINDOW];
        hits = new AtomicIntegerArray(WINDOW);
    }
    
    public void hit(int timestamp) {
        int idx = timestamp % WINDOW;
        synchronized (this) {
            if (timestamps[idx] != timestamp) {
                timestamps[idx] = timestamp;
                hits.set(idx, 1); // New second — reset
            } else {
                hits.incrementAndGet(idx); // Same second — increment
            }
        }
    }
    
    public int getHits(int timestamp) {
        int total = 0;
        for (int i = 0; i < WINDOW; i++) {
            if (timestamp - timestamps[i] < WINDOW) {
                total += hits.get(i);
            }
        }
        return total;
    }
}

// Queue-based approach for comparison
class HitCounterQueue {
    private java.util.Deque<Integer> queue = new java.util.LinkedList<>();
    
    public synchronized void hit(int timestamp) {
        queue.addLast(timestamp);
    }
    
    public synchronized int getHits(int timestamp) {
        while (!queue.isEmpty() && timestamp - queue.peekFirst() >= 300) {
            queue.pollFirst(); // Remove expired
        }
        return queue.size();
    }
}
