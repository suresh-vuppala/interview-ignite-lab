class Solution {
public:
    // O(n log 26) = O(n) — Max-heap: always place most frequent char
    string reorganizeString(string s) {
        int freq[26] = {};
        for (char c : s) freq[c-'a']++;
        
        // Check if impossible: max freq > (n+1)/2
        priority_queue<pair<int,char>> pq; // {freq, char}
        for (int i = 0; i < 26; i++)
            if (freq[i] > 0) pq.push({freq[i], 'a'+i});
        
        string result;
        while (pq.size() > 1) {
            auto [f1, c1] = pq.top(); pq.pop();
            auto [f2, c2] = pq.top(); pq.pop();
            result += c1; result += c2; // Place two different chars
            if (f1 > 1) pq.push({f1-1, c1});
            if (f2 > 1) pq.push({f2-1, c2});
        }
        if (!pq.empty()) {
            if (pq.top().first > 1) return ""; // Impossible
            result += pq.top().second;
        }
        return result;
    }
};