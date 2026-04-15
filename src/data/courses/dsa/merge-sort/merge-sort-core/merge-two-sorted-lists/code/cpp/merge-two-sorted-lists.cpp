#include <vector>
using namespace std;
// ============================================================
// Solution 1: Concatenate + sort — O((M+N) log(M+N))
// ============================================================
#include <algorithm>
class Solution1 {
public:
    vector<int> mergeSorted(vector<int>& a, vector<int>& b) {
        vector<int> result(a.begin(), a.end());
        result.insert(result.end(), b.begin(), b.end());
        sort(result.begin(), result.end()); // Re-sort everything
        return result;
    }
};

// ============================================================
// Solution 2: Two-pointer merge — O(M+N) Time, O(M+N) Space
// ============================================================
class Solution2 {
public:
    vector<int> mergeSorted(vector<int>& a, vector<int>& b) {
        vector<int> result;
        int i=0, j=0;
        while(i<(int)a.size() && j<(int)b.size())
            result.push_back(a[i]<=b[j] ? a[i++] : b[j++]);
        while(i<(int)a.size()) result.push_back(a[i++]);
        while(j<(int)b.size()) result.push_back(b[j++]);
        return result;
    }
};
