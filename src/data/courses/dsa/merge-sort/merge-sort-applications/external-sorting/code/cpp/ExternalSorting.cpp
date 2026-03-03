#include <queue>
#include <vector>
#include <fstream>
using namespace std;

class ExternalSort {
public:
    void externalSort(string inputFile, string outputFile, int chunkSize) {
        vector<string> tempFiles = sortChunks(inputFile, chunkSize);
        mergeChunks(tempFiles, outputFile);
    }
    
    vector<string> sortChunks(string file, int size) {
        vector<string> temps;
        // Read chunks, sort, write to temp files
        return temps;
    }
    
    void mergeChunks(vector<string>& files, string output) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        // k-way merge using min-heap
    }
};