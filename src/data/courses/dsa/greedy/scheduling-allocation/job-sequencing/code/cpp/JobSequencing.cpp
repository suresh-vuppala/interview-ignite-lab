class JobSequencing {
public:
    int maxProfit(vector<int>& profit, vector<int>& deadline) {
        int n = profit.size();
        vector<pair<int, int>> jobs;
        for (int i = 0; i < n; i++) {
            jobs.push_back({profit[i], deadline[i]});
        }
        sort(jobs.begin(), jobs.end(), greater<pair<int, int>>()); // Sort by profit descending
        
        int maxDeadline = *max_element(deadline.begin(), deadline.end());
        vector<int> slot(maxDeadline + 1, -1);
        
        int totalProfit = 0;
        for (auto& job : jobs) {
            for (int j = job.second; j > 0; j--) { // Find latest available slot
                if (slot[j] == -1) {
                    slot[j] = job.first;
                    totalProfit += job.first;
                    break;
                }
            }
        }
        return totalProfit;
    }
};