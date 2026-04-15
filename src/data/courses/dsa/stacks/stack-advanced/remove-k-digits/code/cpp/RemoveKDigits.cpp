#include <string>
#include <stack>
using namespace std;
// ============================================================
// Solution 1: Try all C(N,K) combinations — O(C(N,K) * N) — exponential
// ============================================================
class Solution1 {
public:
    string removeKdigits(string num, int k) {
        // Brute: try removing every combination of k digits
        // Too slow — see Solution 2 for greedy approach
        if(k>=(int)num.size()) return "0";
        string result=num;
        for(int i=0;i<k;i++){
            // Greedy: find first digit where num[j]>num[j+1], remove it
            int j=0;while(j<(int)result.size()-1&&result[j]<=result[j+1])j++;
            result.erase(j,1);
        }
        // Remove leading zeros
        int start=0;while(start<(int)result.size()-1&&result[start]=='0')start++;
        return result.substr(start);
    }
};

// ============================================================
// Solution 2: Monotonic stack — keep smallest digits — O(N)
// ============================================================
class Solution2 {
public:
    string removeKdigits(string num, int k) {
        string st; // Use string as stack for easy result
        for(char c:num){
            while(!st.empty()&&k>0&&st.back()>c){st.pop_back();k--;}
            st.push_back(c);
        }
        while(k-->0) st.pop_back(); // Remove remaining from end
        // Remove leading zeros
        int start=0;while(start<(int)st.size()-1&&st[start]=='0')start++;
        return st.empty()?"0":st.substr(start);
    }
};
