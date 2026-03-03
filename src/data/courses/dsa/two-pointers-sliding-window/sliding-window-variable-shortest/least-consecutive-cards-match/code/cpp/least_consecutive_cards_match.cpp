class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, int> mp;
        int minLen = INT_MAX;
        for (int i = 0; i < cards.size(); i++) {
            if (mp.count(cards[i])) {
                minLen = min(minLen, i - mp[cards[i]] + 1);
            }
            mp[cards[i]] = i;
        }
        return minLen == INT_MAX ? -1 : minLen;
    }
};