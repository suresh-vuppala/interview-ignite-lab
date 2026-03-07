// Time: O(N^2*M) brute, O(N*M*log(min(N,M))) binary+brute, O((N+M)*log(min(N,M))) binary+hash
// Space: O(N) brute, O(L) binary+brute, O(N) binary+hash

#include <string>
#include <unordered_set>
using namespace std;

// Solution 1: Brute Force
int bruteForce(string s1, string s2) {
    int n = s1.size(), m = s2.size();
    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            string substr = s1.substr(i, j - i + 1);
            if (s2.find(substr) != string::npos) {
                maxLen = max(maxLen, (int)substr.size());
            }
        }
    }
    return maxLen;
}

// Solution 2: Binary Search + Brute Force
bool hasCommonSubstring(string& s1, string& s2, int len) {
    for (int i = 0; i <= (int)s1.size() - len; i++) {
        if (s2.find(s1.substr(i, len)) != string::npos) {
            return true;
        }
    }
    return false;
}

int binarySearchBrute(string s1, string s2) {
    int left = 0, right = min(s1.size(), s2.size());
    int result = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (hasCommonSubstring(s1, s2, mid)) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result;
}

// Solution 3: Binary Search + Rolling Hash
unordered_set<long long> getHashes(string& s, int len) {
    if (len == 0) return {};
    long long d = 256, MOD = 1e9 + 7;
    long long h = 1;
    for (int i = 0; i < len - 1; i++) h = (h * d) % MOD;
    
    long long hash = 0;
    for (int i = 0; i < len; i++) {
        hash = (hash * d + s[i]) % MOD;
    }
    unordered_set<long long> hashes = {hash};
    
    for (int i = len; i < (int)s.size(); i++) {
        hash = (d * (hash - s[i - len] * h) + s[i]) % MOD;
        if (hash < 0) hash += MOD;
        hashes.insert(hash);
    }
    return hashes;
}

bool hasCommon(string& s1, string& s2, int len) {
    auto hashes1 = getHashes(s1, len);
    auto hashes2 = getHashes(s2, len);
    for (auto h : hashes1) {
        if (hashes2.count(h)) return true;
    }
    return false;
}

int binarySearchHash(string s1, string s2) {
    int left = 0, right = min(s1.size(), s2.size());
    int result = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (hasCommon(s1, s2, mid)) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result;
}
