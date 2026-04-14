#include <vector>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: Brute Force — check each number — O(N * ???)
// ============================================================
class Solution1 {
    bool isUgly(int n) {
        while(n>1) {
            if(n%2==0) n/=2;
            else if(n%3==0) n/=3;
            else if(n%5==0) n/=5;
            else return false;
        }
        return n==1;
    }
public:
    int nthUglyNumber(int n) {
        int count=0, num=0;
        while(count<n) { num++; if(isUgly(num)) count++; }
        return num;
    }
};

// ============================================================
// Solution 2: DP — Three-pointer merge — O(N) Time, O(N) Space
// ============================================================
class Solution2 {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n); dp[0]=1;
        int i2=0, i3=0, i5=0;
        for(int i=1;i<n;i++) {
            dp[i]=min({dp[i2]*2, dp[i3]*3, dp[i5]*5});
            if(dp[i]==dp[i2]*2) i2++;
            if(dp[i]==dp[i3]*3) i3++;
            if(dp[i]==dp[i5]*5) i5++;
        }
        return dp[n-1];
    }
};
