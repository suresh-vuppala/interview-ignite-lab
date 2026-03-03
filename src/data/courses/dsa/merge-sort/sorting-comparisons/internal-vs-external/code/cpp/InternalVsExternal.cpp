// Internal Sorting
void internalSort(vector<int>& arr) {
    sort(arr.begin(), arr.end()); // All in memory
}

// External Sorting
class ExternalSort {
public:
    void externalSort(string file, int chunkSize) {
        // 1. Divide into chunks
        vector<string> chunks = divideIntoChunks(file, chunkSize);
        // 2. Sort each chunk
        for (auto& chunk : chunks) sortChunk(chunk);
        // 3. Merge chunks
        mergeChunks(chunks);
    }
};