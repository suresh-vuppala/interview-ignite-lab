// Time: O(n log m), Space: O(1)

class MinimumSpeedArriveTime {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        if (hour <= n - 1) return -1;
        
        int left = 1, right = 10000000;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            double time = 0;
            for (int i = 0; i < n - 1; i++) time += ceil((double) dist[i] / mid);
            time += (double) dist[n - 1] / mid;
            
            if (time <= hour) right = mid - 1;
            else left = mid + 1;
        }
        
        return left;
    }
};
