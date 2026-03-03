class Solution {
public:
    vector<int> firstNegative(vector<int>& arr, int k) {
        vector<int> res;
        deque<int> dq;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] < 0) dq.push_back(i);
            if (i >= k - 1) {
                while (!dq.empty() && dq.front() < i - k + 1) dq.pop_front();
                res.push_back(dq.empty() ? 0 : arr[dq.front()]);
            }
        }
        return res;
    }
};