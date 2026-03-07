Practical applications and problems solved using rolling hash technique.

<br>

> Rolling hash enables:
> - O(N+M) pattern matching
> - O(N) duplicate detection
> - O(N log N) longest common substring
> - O(1) string comparison

> Key advantage:
> Convert string problems to integer comparison problems

<br>

---

## Application 1: Pattern Matching (Rabin-Karp)

**Problem:** Find pattern in text.

**Naive:** O(N×M) - compare at each position

**Rolling Hash:** O(N+M) average

**Implementation:**
```cpp
int rabinKarp(string text, string pattern) {
    int n = text.size(), m = pattern.size();
    long long p = 31, M = 1e9+7;
    
    // Compute pattern hash
    long long patHash = 0, txtHash = 0, pow_val = 1;
    for (int i = 0; i < m; i++) {
        patHash = (patHash + (pattern[i]-'a'+1) * pow_val) % M;
        txtHash = (txtHash + (text[i]-'a'+1) * pow_val) % M;
        if (i < m-1) pow_val = (pow_val * p) % M;
    }
    
    // Slide window
    for (int i = 0; i <= n-m; i++) {
        if (patHash == txtHash && text.substr(i, m) == pattern)
            return i;
        
        if (i < n-m) {
            txtHash = (txtHash - (text[i]-'a'+1) + M) % M;
            txtHash = (txtHash * modInverse(p, M)) % M;
            txtHash = (txtHash + (text[i+m]-'a'+1) * pow_val) % M;
        }
    }
    return -1;
}
```

**Time:** O(N+M) average, O(N×M) worst (many collisions)

<br>

---

## Application 2: Duplicate Substring Detection

**Problem:** Find all duplicate substrings of length K.

**Approach:** Hash all K-length substrings, find duplicates.

**Implementation:**
```cpp
vector<int> findDuplicates(string s, int k) {
    int n = s.size();
    unordered_map<long long, vector<int>> hashMap;
    long long p = 31, M = 1e9+7;
    
    // Compute first window hash
    long long hash = 0, pow_val = 1;
    for (int i = 0; i < k; i++) {
        hash = (hash + (s[i]-'a'+1) * pow_val) % M;
        if (i < k-1) pow_val = (pow_val * p) % M;
    }
    hashMap[hash].push_back(0);
    
    // Slide window
    for (int i = k; i < n; i++) {
        hash = (hash - (s[i-k]-'a'+1) + M) % M;
        hash = (hash * modInverse(p, M)) % M;
        hash = (hash + (s[i]-'a'+1) * pow_val) % M;
        hashMap[hash].push_back(i-k+1);
    }
    
    // Find duplicates
    vector<int> result;
    for (auto& [h, indices] : hashMap) {
        if (indices.size() > 1) {
            result.insert(result.end(), indices.begin(), indices.end());
        }
    }
    return result;
}
```

**Time:** O(N), **Space:** O(N)

<br>

---

## Application 3: Longest Common Substring

**Problem:** Find longest common substring of two strings.

**Approach:** Binary search on length + rolling hash.

**Implementation:**
```cpp
int longestCommonSubstring(string s1, string s2) {
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

bool hasCommonSubstring(string s1, string s2, int len) {
    unordered_set<long long> hashes;
    long long p = 31, M = 1e9+7;
    
    // Hash all substrings of s1
    long long hash = 0, pow_val = 1;
    for (int i = 0; i < len; i++) {
        hash = (hash + (s1[i]-'a'+1) * pow_val) % M;
        if (i < len-1) pow_val = (pow_val * p) % M;
    }
    hashes.insert(hash);
    
    for (int i = len; i < s1.size(); i++) {
        hash = (hash - (s1[i-len]-'a'+1) + M) % M;
        hash = (hash * modInverse(p, M)) % M;
        hash = (hash + (s1[i]-'a'+1) * pow_val) % M;
        hashes.insert(hash);
    }
    
    // Check s2 substrings
    hash = 0;
    for (int i = 0; i < len; i++) {
        hash = (hash + (s2[i]-'a'+1) * pow_val) % M;
    }
    if (hashes.count(hash)) return true;
    
    for (int i = len; i < s2.size(); i++) {
        hash = (hash - (s2[i-len]-'a'+1) + M) % M;
        hash = (hash * modInverse(p, M)) % M;
        hash = (hash + (s2[i]-'a'+1) * pow_val) % M;
        if (hashes.count(hash)) return true;
    }
    return false;
}
```

**Time:** O(N log N), **Space:** O(N)

<br>

---

## Application 4: Palindrome Checking

**Problem:** Check if substring is palindrome.

**Approach:** Compare hash(s) with hash(reverse(s)).

**Implementation:**
```cpp
class PalindromeChecker {
    vector<long long> prefixHash, suffixHash, power;
    int n;
    long long p = 31, M = 1e9+7;
    
public:
    PalindromeChecker(string s) {
        n = s.size();
        prefixHash.resize(n+1);
        suffixHash.resize(n+1);
        power.resize(n+1);
        
        power[0] = 1;
        for (int i = 0; i < n; i++) {
            prefixHash[i+1] = (prefixHash[i] + (s[i]-'a'+1) * power[i]) % M;
            power[i+1] = (power[i] * p) % M;
        }
        
        for (int i = n-1; i >= 0; i--) {
            suffixHash[n-i] = (suffixHash[n-i-1] + (s[i]-'a'+1) * power[n-i-1]) % M;
        }
    }
    
    bool isPalindrome(int L, int R) {
        long long hashForward = getHash(prefixHash, L, R);
        long long hashBackward = getHash(suffixHash, n-R-1, n-L-1);
        return hashForward == hashBackward;
    }
    
    long long getHash(vector<long long>& hash, int L, int R) {
        long long val = (hash[R+1] - hash[L] + M) % M;
        return (val * modInverse(power[L])) % M;
    }
};
```

**Time:** O(1) per query after O(N) preprocessing

<br>

---

## Application 5: String Comparison

**Problem:** Compare two substrings in O(1).

**Approach:** Compare their hashes.

**Implementation:**
```cpp
class StringComparator {
    vector<long long> prefix, power;
    long long p = 31, M = 1e9+7;
    
public:
    StringComparator(string s) {
        int n = s.size();
        prefix.resize(n+1);
        power.resize(n+1);
        
        prefix[0] = 0;
        power[0] = 1;
        
        for (int i = 0; i < n; i++) {
            prefix[i+1] = (prefix[i] + (s[i]-'a'+1) * power[i]) % M;
            power[i+1] = (power[i] * p) % M;
        }
    }
    
    bool areEqual(int L1, int R1, int L2, int R2) {
        if (R1 - L1 != R2 - L2) return false;
        return getHash(L1, R1) == getHash(L2, R2);
    }
    
    long long getHash(int L, int R) {
        long long val = (prefix[R+1] - prefix[L] + M) % M;
        return (val * modInverse(power[L])) % M;
    }
};
```

**Time:** O(1) comparison vs O(K) naive

<br>

---

## Application 6: Longest Repeated Substring

**Problem:** Find longest substring that appears at least twice.

**Approach:** Binary search + rolling hash.

**Implementation:**
```cpp
int longestRepeatedSubstring(string s) {
    int left = 1, right = s.size();
    int result = 0;
    
    while (left <= right) {
        int mid = (left + right) / 2;
        if (hasRepeatedSubstring(s, mid)) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result;
}

bool hasRepeatedSubstring(string s, int len) {
    unordered_map<long long, int> seen;
    long long p = 31, M = 1e9+7;
    
    long long hash = 0, pow_val = 1;
    for (int i = 0; i < len; i++) {
        hash = (hash + (s[i]-'a'+1) * pow_val) % M;
        if (i < len-1) pow_val = (pow_val * p) % M;
    }
    seen[hash] = 0;
    
    for (int i = len; i < s.size(); i++) {
        hash = (hash - (s[i-len]-'a'+1) + M) % M;
        hash = (hash * modInverse(p, M)) % M;
        hash = (hash + (s[i]-'a'+1) * pow_val) % M;
        
        if (seen.count(hash)) return true;
        seen[hash] = i - len + 1;
    }
    return false;
}
```

**Time:** O(N log N), **Space:** O(N)

<br>

---

## Summary of Applications

| Application | Time | Space | Use Case |
|-------------|------|-------|----------|
| Pattern Matching | O(N+M) | O(1) | Find pattern in text |
| Duplicate Detection | O(N) | O(N) | Find repeated substrings |
| Longest Common | O(N log N) | O(N) | LCS of two strings |
| Palindrome Check | O(1) | O(N) | Query if substring is palindrome |
| String Compare | O(1) | O(N) | Compare two substrings |
| Longest Repeated | O(N log N) | O(N) | Find longest repeat |

<br>

---

## Key Techniques

1. **Binary Search + Hash:** For optimization problems (longest/shortest)
2. **Hash Map:** For duplicate detection and counting
3. **Double Hashing:** For reducing collision probability
4. **Prefix/Suffix Hash:** For bidirectional queries

> **Common Pattern:** Preprocess O(N) → Query O(1) or O(log N)

<br>
<br>

---

```code```
