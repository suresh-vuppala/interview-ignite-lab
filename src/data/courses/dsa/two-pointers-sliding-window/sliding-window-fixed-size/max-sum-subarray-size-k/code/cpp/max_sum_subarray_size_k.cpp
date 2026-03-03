class Solution {
public:
    int maxSum(vector<int>& arr, int k) {
        int sum = 0, maxSum = INT_MIN;
        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            if (i >= k - 1) {
                maxSum = max(maxSum, sum);
                sum -= arr[i - k + 1];
            }
        }
        return maxSum;
    }
};