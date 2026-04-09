import os

base = "src/data/courses/dsa/greedy"

# Greedy vs DP
greedy_vs_dp_java = """class GreedyVsDP {
    // Greedy: Activity Selection - Choose activities that finish earliest
    public int maxActivities(int[] start, int[] end) {
        Arrays.sort(end); // Sort by end time
        int count = 1, lastEnd = end[0];
        for (int i = 1; i < end.length; i++) {
            if (start[i] >= lastEnd) { // No overlap with previous activity
                count++;
                lastEnd = end[i];
            }
        }
        return count;
    }
    
    // DP: 0/1 Knapsack - Need to consider all possibilities
    public int knapsack(int[] wt, int[] val, int W) {
        int n = wt.length;
        int[] dp = new int[W + 1]; // dp[w] = max value with weight w
        for (int i = 0; i < n; i++) {
            for (int w = W; w >= wt[i]; w--) { // Iterate backwards to avoid using same item twice
                dp[w] = Math.max(dp[w], dp[w - wt[i]] + val[i]);
            }
        }
        return dp[W];
    }
}"""

greedy_vs_dp_cpp = """class GreedyVsDP {
public:
    // Greedy: Activity Selection - Choose activities that finish earliest
    int maxActivities(vector<int>& start, vector<int>& end) {
        sort(end.begin(), end.end()); // Sort by end time
        int count = 1, lastEnd = end[0];
        for (int i = 1; i < end.size(); i++) {
            if (start[i] >= lastEnd) { // No overlap with previous activity
                count++;
                lastEnd = end[i];
            }
        }
        return count;
    }
    
    // DP: 0/1 Knapsack - Need to consider all possibilities
    int knapsack(vector<int>& wt, vector<int>& val, int W) {
        int n = wt.size();
        vector<int> dp(W + 1, 0); // dp[w] = max value with weight w
        for (int i = 0; i < n; i++) {
            for (int w = W; w >= wt[i]; w--) { // Iterate backwards to avoid using same item twice
                dp[w] = max(dp[w], dp[w - wt[i]] + val[i]);
            }
        }
        return dp[W];
    }
};"""

greedy_vs_dp_python = """def max_activities(start, end):
    # Greedy: Activity Selection - Choose activities that finish earliest
    end.sort()  # Sort by end time
    count, last_end = 1, end[0]
    for i in range(1, len(end)):
        if start[i] >= last_end:  # No overlap with previous activity
            count += 1
            last_end = end[i]
    return count

def knapsack(wt, val, W):
    # DP: 0/1 Knapsack - Need to consider all possibilities
    n = len(wt)
    dp = [0] * (W + 1)  # dp[w] = max value with weight w
    for i in range(n):
        for w in range(W, wt[i] - 1, -1):  # Iterate backwards to avoid using same item twice
            dp[w] = max(dp[w], dp[w - wt[i]] + val[i])
    return dp[W]"""

# Activity Selection
activity_java = """class ActivitySelection {
    public int maxActivities(int[] start, int[] end) {
        int n = start.length;
        int[][] activities = new int[n][2];
        for (int i = 0; i < n; i++) {
            activities[i] = new int[]{start[i], end[i]};
        }
        Arrays.sort(activities, (a, b) -> a[1] - b[1]); // Sort by end time
        
        int count = 1, lastEnd = activities[0][1]; // Select first activity
        for (int i = 1; i < n; i++) {
            if (activities[i][0] >= lastEnd) { // No overlap
                count++;
                lastEnd = activities[i][1];
            }
        }
        return count;
    }
}"""

activity_cpp = """class ActivitySelection {
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
};"""

activity_python = """def max_activities(start, end):
    activities = sorted(zip(start, end), key=lambda x: x[1])  # Sort by end time
    count, last_end = 1, activities[0][1]  # Select first activity
    for s, e in activities[1:]:
        if s >= last_end:  # No overlap
            count += 1
            last_end = e
    return count"""

# Non-overlapping Intervals
non_overlap_java = """class NonOverlappingIntervals {
    public int eraseOverlapIntervals(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> a[1] - b[1]); // Sort by end time
        int count = 1, end = intervals[0][1]; // Count non-overlapping intervals
        for (int i = 1; i < intervals.length; i++) {
            if (intervals[i][0] >= end) { // No overlap
                count++;
                end = intervals[i][1];
            }
        }
        return intervals.length - count; // Total - non-overlapping = to remove
    }
}"""

non_overlap_cpp = """class NonOverlappingIntervals {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            return a[1] < b[1]; // Sort by end time
        });
        int count = 1, end = intervals[0][1]; // Count non-overlapping intervals
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= end) { // No overlap
                count++;
                end = intervals[i][1];
            }
        }
        return intervals.size() - count; // Total - non-overlapping = to remove
    }
};"""

non_overlap_python = """def erase_overlap_intervals(intervals):
    intervals.sort(key=lambda x: x[1])  # Sort by end time
    count, end = 1, intervals[0][1]  # Count non-overlapping intervals
    for i in range(1, len(intervals)):
        if intervals[i][0] >= end:  # No overlap
            count += 1
            end = intervals[i][1]
    return len(intervals) - count  # Total - non-overlapping = to remove"""

# Merge Intervals
merge_java = """class MergeIntervals {
    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> a[0] - b[0]); // Sort by start time
        List<int[]> result = new ArrayList<>();
        int[] current = intervals[0];
        for (int i = 1; i < intervals.length; i++) {
            if (intervals[i][0] <= current[1]) { // Overlapping
                current[1] = Math.max(current[1], intervals[i][1]); // Extend end
            } else {
                result.add(current); // Add merged interval
                current = intervals[i];
            }
        }
        result.add(current);
        return result.toArray(new int[result.size()][]);
    }
}"""

merge_cpp = """class MergeIntervals {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end()); // Sort by start time
        vector<vector<int>> result;
        vector<int> current = intervals[0];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= current[1]) { // Overlapping
                current[1] = max(current[1], intervals[i][1]); // Extend end
            } else {
                result.push_back(current); // Add merged interval
                current = intervals[i];
            }
        }
        result.push_back(current);
        return result;
    }
};"""

merge_python = """def merge(intervals):
    intervals.sort()  # Sort by start time
    result = [intervals[0]]
    for start, end in intervals[1:]:
        if start <= result[-1][1]:  # Overlapping
            result[-1][1] = max(result[-1][1], end)  # Extend end
        else:
            result.append([start, end])  # Add merged interval
    return result"""

# Write files
with open(f"{base}/introduction/greedy-vs-dp/code/java/GreedyVsDp.java", "w") as f:
    f.write(greedy_vs_dp_java)
with open(f"{base}/introduction/greedy-vs-dp/code/cpp/GreedyVsDp.cpp", "w") as f:
    f.write(greedy_vs_dp_cpp)
with open(f"{base}/introduction/greedy-vs-dp/code/python/greedy-vs-dp.py", "w") as f:
    f.write(greedy_vs_dp_python)

with open(f"{base}/interval-based/activity-selection/code/java/ActivitySelection.java", "w") as f:
    f.write(activity_java)
with open(f"{base}/interval-based/activity-selection/code/cpp/ActivitySelection.cpp", "w") as f:
    f.write(activity_cpp)
with open(f"{base}/interval-based/activity-selection/code/python/activity-selection.py", "w") as f:
    f.write(activity_python)

with open(f"{base}/interval-based/non-overlapping-intervals/code/java/NonOverlappingIntervals.java", "w") as f:
    f.write(non_overlap_java)
with open(f"{base}/interval-based/non-overlapping-intervals/code/cpp/NonOverlappingIntervals.cpp", "w") as f:
    f.write(non_overlap_cpp)
with open(f"{base}/interval-based/non-overlapping-intervals/code/python/non-overlapping-intervals.py", "w") as f:
    f.write(non_overlap_python)

with open(f"{base}/interval-based/merge-intervals/code/java/MergeIntervals.java", "w") as f:
    f.write(merge_java)
with open(f"{base}/interval-based/merge-intervals/code/cpp/MergeIntervals.cpp", "w") as f:
    f.write(merge_cpp)
with open(f"{base}/interval-based/merge-intervals/code/python/merge-intervals.py", "w") as f:
    f.write(merge_python)

print("Greedy lessons part 1 updated with comments")
