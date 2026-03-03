class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mp;
        int left = 0, maxLen = 0;
        for (int right = 0; right < fruits.size(); right++) {
            mp[fruits[right]]++;
            while (mp.size() > 2) {
                if (--mp[fruits[left]] == 0) mp.erase(fruits[left]);
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};