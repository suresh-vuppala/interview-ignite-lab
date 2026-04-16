// DESIGN: Hit Counter — LLD (Java) | Circular Array O(1)/O(W)
import java.util.*;
import java.util.concurrent.atomic.*;

class HitCounter {
    static final int WINDOW = 300;
    int[] timestamps = new int[WINDOW];
    AtomicIntegerArray hits = new AtomicIntegerArray(WINDOW);

    public synchronized void hit(int timestamp) {
        int idx = timestamp % WINDOW;
        if (timestamps[idx] != timestamp) { timestamps[idx] = timestamp; hits.set(idx, 1); }
        else hits.incrementAndGet(idx);
    }

    public int getHits(int timestamp) {
        int total = 0;
        for (int i = 0; i < WINDOW; i++) if (timestamp - timestamps[i] < WINDOW) total += hits.get(i);
        return total;
    }
}

class HitCounterQueue {
    Deque<Integer> queue = new LinkedList<>();
    public synchronized void hit(int ts) { queue.addLast(ts); }
    public synchronized int getHits(int ts) {
        while (!queue.isEmpty() && ts-queue.peekFirst()>=300) queue.pollFirst();
        return queue.size();
    }
}

public class HitCounterSystem {
    public static void main(String[] args) {
        System.out.println("=== Hit Counter — Java ===");
        HitCounter c = new HitCounter();
        c.hit(1); c.hit(2); c.hit(3); c.hit(3); c.hit(100); c.hit(200); c.hit(300);
        System.out.println("getHits(300): " + c.getHits(300));
        System.out.println("getHits(301): " + c.getHits(301));
        System.out.println("getHits(600): " + c.getHits(600));
        System.out.println("=== Complete ===");
    }
}
// SUMMARY: Circular array (O(1) hit, O(W) getHits), AtomicIntegerArray for thread safety
