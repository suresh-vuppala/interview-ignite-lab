class ActivitySelection {
public:
    int maxActivities(vector<int>& start, vector<int>& end) {
        int n = start.size();
        vector<pair<int, int>> activities;
        for (int i = 0; i < n; i++) {
            activities.push_back({end[i], start[i]});
        }
        sort(activities.begin(), activities.end()); // Sort by end time
        
        int count = 1, lastEnd = activities[0].first; // Select first activity
        for (int i = 1; i < n; i++) {
            if (activities[i].second >= lastEnd) { // No overlap
                count++;
                lastEnd = activities[i].first;
            }
        }
        return count;
    }
};