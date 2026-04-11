class Solution {
public:
    // O(n) time, O(n) space — Two-pass: left-to-right, right-to-left
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1); // Everyone gets at least 1
        
        // Left pass: if rating[i] > rating[i-1], give more than left neighbor
        for (int i = 1; i < n; i++)
            if (ratings[i] > ratings[i-1])
                candies[i] = candies[i-1] + 1;
        
        // Right pass: if rating[i] > rating[i+1], ensure more than right neighbor
        for (int i = n-2; i >= 0; i--)
            if (ratings[i] > ratings[i+1])
                candies[i] = max(candies[i], candies[i+1] + 1);
        
        int total = 0;
        for (int c : candies) total += c;
        return total;
    }
};