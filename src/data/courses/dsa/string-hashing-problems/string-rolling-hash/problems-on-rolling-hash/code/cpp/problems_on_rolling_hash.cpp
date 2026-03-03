#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    string longestDupSubstring(string s) {
        int n = s.size();
        int left = 1, right = n;
        string res = "";
        
        while (left <= right) {
            int mid = (left + right) / 2;
            string dup = search(s, mid);
            if (!dup.empty()) {
                res = dup;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return res;
    }
    
    string search(string& s, int len) {
        long long p = 31, mod = 1e9+7;
        long long hash = 0, pow = 1;
        unordered_map<long long, vector<int>> map;
        
        for (int i = 0; i < len; i++) {
            hash = (hash + (s[i]-'a'+1)*pow) % mod;
            pow = (pow*p) % mod;
        }
        map[hash].push_back(0);
        
        for (int i = len; i < s.size(); i++) {
            hash = (hash - (s[i-len]-'a'+1) + mod) % mod;
            hash = (hash + (s[i]-'a'+1)*pow) % mod;
            
            if (map.count(hash)) {
                for (int idx : map[hash]) {
                    if (s.substr(idx, len) == s.substr(i-len+1, len))
                        return s.substr(idx, len);
                }
            }
            map[hash].push_back(i-len+1);
        }
        return "";
    }
};