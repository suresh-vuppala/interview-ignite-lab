#include <vector>
#include <string>
using namespace std;

class RollingHash {
    vector<long long> hash, pow;
    int p = 31, mod = 1e9+7;
public:
    RollingHash(string s) {
        int n = s.size();
        hash.resize(n+1);
        pow.resize(n+1);
        pow[0] = 1;
        for (int i = 0; i < n; i++) {
            hash[i+1] = (hash[i] + (s[i]-'a'+1)*pow[i]) % mod;
            pow[i+1] = (pow[i]*p) % mod;
        }
    }
    
    long long getHash(int l, int r) {
        return (hash[r+1] - hash[l] + mod) % mod;
    }
};