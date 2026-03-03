import java.util.*;

public class Heaps {
    static class MinHeap {
        private List<Integer> heap;
        
        public MinHeap() {
            heap = new ArrayList<>();
        }
        
        private int parent(int i) { return (i - 1) / 2; }
        private int left(int i) { return 2 * i + 1; }
        private int right(int i) { return 2 * i + 2; }
        
        public void insert(int val) {
            heap.add(val);
            bubbleUp(heap.size() - 1);
        }
        
        private void bubbleUp(int i) {
            while (i > 0 && heap.get(i) < heap.get(parent(i))) {
                Collections.swap(heap, i, parent(i));
                i = parent(i);
            }
        }
        
        public int extractMin() {
            if (heap.isEmpty()) throw new RuntimeException("Heap is empty");
            int min = heap.get(0);
            heap.set(0, heap.get(heap.size() - 1));
            heap.remove(heap.size() - 1);
            if (!heap.isEmpty()) bubbleDown(0);
            return min;
        }
        
        private void bubbleDown(int i) {
            int minIndex = i;
            int l = left(i);
            int r = right(i);
            
            if (l < heap.size() && heap.get(l) < heap.get(minIndex))
                minIndex = l;
            if (r < heap.size() && heap.get(r) < heap.get(minIndex))
                minIndex = r;
            
            if (i != minIndex) {
                Collections.swap(heap, i, minIndex);
                bubbleDown(minIndex);
            }
        }
        
        public int peek() {
            if (heap.isEmpty()) throw new RuntimeException("Heap is empty");
            return heap.get(0);
        }
    }
}
