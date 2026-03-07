// Time: O(N^3+N^2*M) brute, O(N+M) sliding window, O(N*M*log(N)) binary search
// Space: O(M)

#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

// Solution 1: Brute Force
string bruteForce(string s, string t) {
    if (s.empty() || t.empty() || t.size() > s.size()) {
        return "";
    }
    
    unordered_map<char, int> target;
    for (char c : t) target[c]++;
    
    int minLen = INT_MAX;
    string result = "";
    
    for (int i = 0; i < s.size(); i++) {
        for (int j = i; j < s.size(); j++) {
            unordered_map<char, int> window;
            for (int k = i; k <= j; k++) {
                window[s[k]]++;
            }
            
            bool valid = true;
            for (auto& p : target) {
                if (window[p.first] < p.second) {
                    valid = false;
                    break;
                }
            }
            
            if (valid && j - i + 1 < minLen) {
                minLen = j - i + 1;
                result = s.substr(i, j - i + 1);
            }
        }
    }
    
    return result;
}

// Solution 2: Sliding Window (Optimal)
string slidingWindow(string s, string t) {
    if (s.empty() || t.empty() || t.size() > s.size()) {
        return "";
    }
    
    unordered_map<char, int> target, window;
    for (char c : t) target[c]++;
    
    int required = target.size();
    int formed = 0;
    
    int left = 0;
    int minLen = INT_MAX;
    string result = "";
    
    for (int right = 0; right < s.size(); right++) {
        char c = s[right];
        window[c]++;
        
        if (target.count(c) && window[c] == target[c]) {
            formed++;
        }
        
        while (formed == required && left <= right) {
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                result = s.substr(left, right - left + 1);
            }
            
            char leftChar = s[left];
            window[leftChar]--;
            if (target.count(leftChar) && window[leftChar] < target[leftChar]) {
                formed--;
            }
            left++;
        }
    }
    
    return result;
}

// Solution 3: Binary Search on Length
string hasValidWindow(string& s, unordered_map<char, int>& target, int length) {
    for (int i = 0; i <= (int)s.size() - length; i++) {
        unordered_map<char, int> window;
        for (int j = i; j < i + length; j++) {
            window[s[j]]++;
        }
        
        bool valid = true;
        for (auto& p : target) {
            if (window[p.first] < p.second) {
                valid = false;
                break;
            }
        }
        
        if (valid) {
            return s.substr(i, length);
        }
    }
    return "";
}

string binarySearch(string s, string t) {
    if (s.empty() || t.empty() || t.size() > s.size()) {
        return "";
    }
    
    unordered_map<char, int> target;
    for (char c : t) target[c]++;
    
    int left = t.size(), right = s.size();
    string result = "";
    
    while (left <= right) {
        int mid = (left + right) / 2;
        string window = hasValidWindow(s, target, mid);
        if (!window.empty()) {
            result = window;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    return result;
}
