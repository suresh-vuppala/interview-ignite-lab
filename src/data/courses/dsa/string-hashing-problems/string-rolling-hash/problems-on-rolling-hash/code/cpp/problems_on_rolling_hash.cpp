// Applications of Rolling Hash - Complete Implementations

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// Application 1: Pattern Matching (Rabin-Karp)
int rabinKarp(string text, string pattern) {
    int n = text.size(), m = pattern.size();
    long long p = 31, mod = 1e9+7;
    
    long long patHash = 0, txtHash = 0, powVal = 1;
    for (int i = 0; i < m; i++) {
        patHash = (patHash + (pattern[i]-'a'+1) * powVal) % mod;
        txtHash = (txtHash + (text[i]-'a'+1) * powVal) % mod;
        if (i < m-1) powVal = (powVal * p) % mod;
    }
    
    for (int i = 0; i <= n-m; i++) {
        if (patHash == txtHash && text.substr(i, m) == pattern)
            return i;
        if (i < n-m) {
            txtHash = (txtHash - (text[i]-'a'+1) + mod) % mod;
            txtHash = (txtHash / p) % mod;
            txtHash = (txtHash + (text[i+m]-'a'+1) * powVal) % mod;
        }
    }
    return -1;
}

// Application 2: Duplicate Substring Detection
vector<int> findDuplicates(string s, int k) {
    int n = s.size();
    unordered_map<long long, vector<int>> hashMap;
    long long p = 31, mod = 1e9+7;
    
    long long hash = 0, powVal = 1;
    for (int i = 0; i < k; i++) {
        hash = (hash + (s[i]-'a'+1) * powVal) % mod;
        if (i < k-1) powVal = (powVal * p) % mod;
    }
    hashMap[hash].push_back(0);
    
    for (int i = k; i < n; i++) {
        hash = (hash - (s[i-k]-'a'+1) + mod) % mod;
        hash = (hash / p) % mod;
        hash = (hash + (s[i]-'a'+1) * powVal) % mod;
        hashMap[hash].push_back(i-k+1);
    }
    
    vector<int> result;
    for (auto& [h, indices] : hashMap) {
        if (indices.size() > 1) {
            result.insert(result.end(), indices.begin(), indices.end());
        }
    }
    return result;
}

// Application 3: Longest Common Substring
int longestCommonSubstring(string s1, string s2) {
    auto hasCommon = [&](int length) {
        unordered_set<long long> hashes;
        long long p = 31, mod = 1e9+7;
        
        long long hash = 0, powVal = 1;
        for (int i = 0; i < length; i++) {
            hash = (hash * p + (s1[i]-'a'+1)) % mod;
            if (i < length-1) powVal = (powVal * p) % mod;
        }
        hashes.insert(hash);
        
        for (int i = length; i < s1.size(); i++) {
            hash = (hash - (s1[i-length]-'a'+1) * powVal % mod + mod) % mod;
            hash = (hash * p + (s1[i]-'a'+1)) % mod;
            hashes.insert(hash);
        }
        
        hash = 0;
        for (int i = 0; i < length; i++) {
            hash = (hash * p + (s2[i]-'a'+1)) % mod;
        }
        if (hashes.count(hash)) return true;
        
        for (int i = length; i < s2.size(); i++) {
            hash = (hash - (s2[i-length]-'a'+1) * powVal % mod + mod) % mod;
            hash = (hash * p + (s2[i]-'a'+1)) % mod;
            if (hashes.count(hash)) return true;
        }
        return false;
    };
    
    int left = 0, right = min(s1.size(), s2.size());
    int result = 0;
    
    while (left <= right) {
        int mid = (left + right) / 2;
        if (hasCommon(mid)) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result;
}

// Application 4: Longest Repeated Substring
int longestRepeatedSubstring(string s) {
    auto hasRepeated = [&](int length) {
        unordered_map<long long, int> seen;
        long long p = 31, mod = 1e9+7;
        
        long long hash = 0, powVal = 1;
        for (int i = 0; i < length; i++) {
            hash = (hash * p + (s[i]-'a'+1)) % mod;
            if (i < length-1) powVal = (powVal * p) % mod;
        }
        seen[hash] = 0;
        
        for (int i = length; i < s.size(); i++) {
            hash = (hash - (s[i-length]-'a'+1) * powVal % mod + mod) % mod;
            hash = (hash * p + (s[i]-'a'+1)) % mod;
            if (seen.count(hash)) return true;
            seen[hash] = i - length + 1;
        }
        return false;
    };
    
    int left = 1, right = s.size();
    int result = 0;
    
    while (left <= right) {
        int mid = (left + right) / 2;
        if (hasRepeated(mid)) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result;
}
