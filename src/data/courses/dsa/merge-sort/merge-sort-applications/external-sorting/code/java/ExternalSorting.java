import java.util.*;

class ExternalSort {
    void externalSort(String inputFile, String outputFile, int chunkSize) {
        List<String> tempFiles = sortChunks(inputFile, chunkSize);
        mergeChunks(tempFiles, outputFile);
    }
    
    List<String> sortChunks(String file, int size) {
        // Read chunks, sort, write to temp files
        List<String> temps = new ArrayList<>();
        // Implementation: read size elements, sort, write
        return temps;
    }
    
    void mergeChunks(List<String> files, String output) {
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        // k-way merge using min-heap
    }
}