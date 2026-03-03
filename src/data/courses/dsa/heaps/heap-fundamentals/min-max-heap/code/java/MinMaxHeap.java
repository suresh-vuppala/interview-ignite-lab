import java.util.*;

public class MinMaxHeap {
    static class MaxHeap {
        private List<Integer> heap = new ArrayList<>();
        
        private int parent(int i) { return (i - 1) / 2; }
        private int left(int i) { return 2 * i + 1; }
        private int right(int i) { return 2 * i + 2; }
        
        public void insert(int val) {
            heap.add(val);
            bubbleUp(heap.size() - 1);
        }
        
        private void bubbleUp(int i) {
            while (i > 0 && heap.get(i) > heap.get(parent(i))) {
                Collections.swap(heap, i, parent(i));
                i = parent(i);
            }
        }
        
        public int extractMax() {
            int max = heap.get(0);
            heap.set(0, heap.get(heap.size() - 1));
            heap.remove(heap.size() - 1);
            if (!heap.isEmpty()) bubbleDown(0);
            return max;
        }
        
        private void bubbleDown(int i) {
            int maxIndex = i;
            int l = left(i);
            int r = right(i);
            
            if (l < heap.size() && heap.get(l) > heap.get(maxIndex))
                maxIndex = l;
            if (r < heap.size() && heap.get(r) > heap.get(maxIndex))
                maxIndex = r;
            
            if (i != maxIndex) {
                Collections.swap(heap, i, maxIndex);
                bubbleDown(maxIndex);
            }
        }
    }
}
