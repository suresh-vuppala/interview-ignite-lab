#include <vector>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: Unstable sort (Selection Sort) — equal elements may reorder
// ============================================================
class Solution1 {
public:
    void unstableSort(vector<pair<int,char>>& items) {
        int n=items.size();
        for(int i=0;i<n-1;i++){
            int minIdx=i;
            for(int j=i+1;j<n;j++) if(items[j].first<items[minIdx].first) minIdx=j;
            swap(items[i],items[minIdx]); // May reorder equal-key elements!
        }
    }
};

// ============================================================
// Solution 2: Stable sort (Insertion Sort/Merge Sort) — preserves relative order
// ============================================================
class Solution2 {
public:
    void stableSort(vector<pair<int,char>>& items) {
        // Insertion sort is stable: equal elements stay in original order
        for(int i=1;i<(int)items.size();i++){
            auto key=items[i]; int j=i-1;
            while(j>=0 && items[j].first>key.first){items[j+1]=items[j];j--;}
            items[j+1]=key; // Only moves past STRICTLY greater — stable!
        }
    }
};
