#include <vector>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: Counting Sort — O(N+K) Time, non-comparison
// ============================================================
class Solution1 {
public:
    void countingSort(vector<int>& nums) {
        if(nums.empty()) return;
        int mx=*max_element(nums.begin(),nums.end());
        int mn=*min_element(nums.begin(),nums.end());
        vector<int> count(mx-mn+1, 0);
        for(int x:nums) count[x-mn]++;
        int idx=0;
        for(int i=0;i<(int)count.size();i++)
            while(count[i]-->0) nums[idx++]=i+mn;
    }
};

// ============================================================
// Solution 2: Radix Sort (LSD) — O(d*(N+b)) Time, non-comparison
// ============================================================
class Solution2 {
    void countingSortByDigit(vector<int>& nums, int exp) {
        int n=nums.size(); vector<int> output(n), count(10,0);
        for(int x:nums) count[(x/exp)%10]++;
        for(int i=1;i<10;i++) count[i]+=count[i-1];
        for(int i=n-1;i>=0;i--){output[--count[(nums[i]/exp)%10]]=nums[i];}
        nums=output;
    }
public:
    void radixSort(vector<int>& nums) {
        if(nums.empty()) return;
        int mx=*max_element(nums.begin(),nums.end());
        for(int exp=1; mx/exp>0; exp*=10)
            countingSortByDigit(nums, exp);
    }
};
