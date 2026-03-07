// Time: O(2^(n/2) * n/2), Space: O(2^(n/2))

class SubsetSumMITM {
public:
    bool subsetSum(vector<int>& arr, int target) {
        int n = arr.size(), mid = n / 2;
        
        vector<long long> leftSums = generateSums(arr, 0, mid);
        vector<long long> rightSums = generateSums(arr, mid, n);
        
        sort(leftSums.begin(), leftSums.end());
        
        for (long long rightSum : rightSums) {
            long long need = target - rightSum;
            if (binary_search(leftSums.begin(), leftSums.end(), need)) return true;
        }
        
        return false;
    }
    
private:
    vector<long long> generateSums(vector<int>& arr, int start, int end) {
        vector<long long> sums;
        int len = end - start;
        for (int mask = 0; mask < (1 << len); mask++) {
            long long sum = 0;
            for (int i = 0; i < len; i++) {
                if (mask & (1 << i)) sum += arr[start + i];
            }
            sums.push_back(sum);
        }
        return sums;
    }
};
