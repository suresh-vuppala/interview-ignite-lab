class Solution {
public:
    vector<int> subarraySum(vector<int>& arr, int k) {
        vector<int> res;
        int sum = 0;
        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            if (i >= k - 1) {
                res.push_back(sum);
                sum -= arr[i - k + 1];
            }
        }
        return res;
    }
};