// Time: O(n log(m * k)), Space: O(1)

class MinimumTimeCompleteTrips {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long left = 1, right = (long long) *min_element(time.begin(), time.end()) * totalTrips;
        
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long trips = 0;
            for (int t : time) trips += mid / t;
            
            if (trips >= totalTrips) right = mid - 1;
            else left = mid + 1;
        }
        
        return left;
    }
};
