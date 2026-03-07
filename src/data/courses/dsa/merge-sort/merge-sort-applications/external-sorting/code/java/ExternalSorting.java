// Time: O(N log N), Space: O(M) where M is chunk size

import java.util.*;

public class ExternalSorting {
    static class Element implements Comparable<Element> {
        int value, chunkIdx, elemIdx;
        Element(int v, int c, int e) { value = v; chunkIdx = c; elemIdx = e; }
        public int compareTo(Element other) { return this.value - other.value; }
    }
    
    public static List<Integer> externalSort(int[] data, int chunkSize) {
        List<List<Integer>> chunks = new ArrayList<>();
        
        // Phase 1: Create sorted chunks
        for (int i = 0; i < data.length; i += chunkSize) {
            List<Integer> chunk = new ArrayList<>();
            for (int j = i; j < Math.min(i + chunkSize, data.length); j++) {
                chunk.add(data[j]);
            }
            Collections.sort(chunk);
            chunks.add(chunk);
        }
        
        // Phase 2: K-way merge
        List<Integer> result = new ArrayList<>();
        PriorityQueue<Element> heap = new PriorityQueue<>();
        
        for (int i = 0; i < chunks.size(); i++) {
            if (!chunks.get(i).isEmpty()) {
                heap.offer(new Element(chunks.get(i).get(0), i, 0));
            }
        }
        
        while (!heap.isEmpty()) {
            Element e = heap.poll();
            result.add(e.value);
            
            if (e.elemIdx + 1 < chunks.get(e.chunkIdx).size()) {
                int nextVal = chunks.get(e.chunkIdx).get(e.elemIdx + 1);
                heap.offer(new Element(nextVal, e.chunkIdx, e.elemIdx + 1));
            }
        }
        
        return result;
    }
    
    public static void main(String[] args) {
        int[] data = {64, 34, 25, 12, 22, 11, 90, 88, 45, 50, 33, 17};
        List<Integer> sorted = externalSort(data, 3);
        System.out.println(sorted);
    }
}
