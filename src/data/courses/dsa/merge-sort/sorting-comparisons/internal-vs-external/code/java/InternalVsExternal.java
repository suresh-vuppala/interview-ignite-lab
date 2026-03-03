// Internal Sorting (in-memory)
void internalSort(int[] arr) {
    Arrays.sort(arr); // All data in memory
}

// External Sorting (disk-based)
class ExternalSort {
    void externalSort(String file, int chunkSize) {
        // 1. Divide into chunks
        List<String> chunks = divideIntoChunks(file, chunkSize);
        // 2. Sort each chunk in memory
        for (String chunk : chunks) sortChunk(chunk);
        // 3. Merge sorted chunks
        mergeChunks(chunks);
    }
}