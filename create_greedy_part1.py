import os
import json

lessons = [
    {
        "section": "introduction",
        "slug": "greedy-vs-dp",
        "title": "Greedy Choice Property and When Greedy works vs when DP is required",
        "md": """## Problem Statement

Understand when to use Greedy algorithms versus Dynamic Programming.

## Greedy Choice Property

A problem has greedy choice property if:
- Making locally optimal choice leads to global optimum
- Choice doesn't depend on future subproblems
- Once made, choice is never reconsidered

## When to Use Greedy

- Problem has optimal substructure
- Greedy choice property holds
- Examples: Activity Selection, Huffman Coding

## When to Use DP

- Overlapping subproblems exist
- Need to consider all possibilities
- Examples: 0/1 Knapsack, Longest Common Subsequence

## Code

```code```""",
        "java": """class GreedyVsDP {
    // Greedy: Activity Selection
    public int maxActivities(int[] start, int[] end) {
        Arrays.sort(end);
        int count = 1, lastEnd = end[0];
        for (int i = 1; i < end.length; i++) {
            if (start[i] >= lastEnd) {
                count++;
                lastEnd = end[i];
            }
        }
        return count;
    }
    
    // DP: 0/1 Knapsack
    public int knapsack(int[] wt, int[] val, int W) {
        int n = wt.length;
        int[] dp = new int[W + 1];
        for (int i = 0; i < n; i++) {
            for (int w = W; w >= wt[i]; w--) {
                dp[w] = Math.max(dp[w], dp[w - wt[i]] + val[i]);
            }
        }
        return dp[W];
    }
}""",
        "cpp": """class GreedyVsDP {
public:
    int maxActivities(vector<int>& start, vector<int>& end) {
        sort(end.begin(), end.end());
        int count = 1, lastEnd = end[0];
        for (int i = 1; i < end.size(); i++) {
            if (start[i] >= lastEnd) {
                count++;
                lastEnd = end[i];
            }
        }
        return count;
    }
    
    int knapsack(vector<int>& wt, vector<int>& val, int W) {
        int n = wt.size();
        vector<int> dp(W + 1, 0);
        for (int i = 0; i < n; i++) {
            for (int w = W; w >= wt[i]; w--) {
                dp[w] = max(dp[w], dp[w - wt[i]] + val[i]);
            }
        }
        return dp[W];
    }
};""",
        "python": """def max_activities(start, end):
    end.sort()
    count, last_end = 1, end[0]
    for i in range(1, len(end)):
        if start[i] >= last_end:
            count += 1
            last_end = end[i]
    return count

def knapsack(wt, val, W):
    n = len(wt)
    dp = [0] * (W + 1)
    for i in range(n):
        for w in range(W, wt[i] - 1, -1):
            dp[w] = max(dp[w], dp[w - wt[i]] + val[i])
    return dp[W]"""
    },
    {
        "section": "interval-based",
        "slug": "activity-selection",
        "title": "Activity Selection",
        "md": """## Problem Statement

Given start and end times of activities, select maximum number of non-overlapping activities.

## Approach

1. Sort activities by end time
2. Select first activity
3. For each activity, if start >= last end, select it

## Complexity

- Time: O(n log n)
- Space: O(1)

## Code

```code```""",
        "java": """class ActivitySelection {
    public int maxActivities(int[] start, int[] end) {
        int n = start.length;
        int[][] activities = new int[n][2];
        for (int i = 0; i < n; i++) {
            activities[i] = new int[]{start[i], end[i]};
        }
        Arrays.sort(activities, (a, b) -> a[1] - b[1]);
        
        int count = 1, lastEnd = activities[0][1];
        for (int i = 1; i < n; i++) {
            if (activities[i][0] >= lastEnd) {
                count++;
                lastEnd = activities[i][1];
            }
        }
        return count;
    }
}""",
        "cpp": """class ActivitySelection {
public:
    int maxActivities(vector<int>& start, vector<int>& end) {
        int n = start.size();
        vector<pair<int, int>> activities;
        for (int i = 0; i < n; i++) {
            activities.push_back({end[i], start[i]});
        }
        sort(activities.begin(), activities.end());
        
        int count = 1, lastEnd = activities[0].first;
        for (int i = 1; i < n; i++) {
            if (activities[i].second >= lastEnd) {
                count++;
                lastEnd = activities[i].first;
            }
        }
        return count;
    }
};""",
        "python": """def max_activities(start, end):
    activities = sorted(zip(start, end), key=lambda x: x[1])
    count, last_end = 1, activities[0][1]
    for s, e in activities[1:]:
        if s >= last_end:
            count += 1
            last_end = e
    return count"""
    },
    {
        "section": "interval-based",
        "slug": "non-overlapping-intervals",
        "title": "Non-overlapping Intervals",
        "md": """## Problem Statement

Find minimum number of intervals to remove to make rest non-overlapping.

## Approach

1. Sort by end time
2. Count non-overlapping intervals
3. Return total - non-overlapping count

## Complexity

- Time: O(n log n)
- Space: O(1)

## Code

```code```""",
        "java": """class NonOverlappingIntervals {
    public int eraseOverlapIntervals(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> a[1] - b[1]);
        int count = 1, end = intervals[0][1];
        for (int i = 1; i < intervals.length; i++) {
            if (intervals[i][0] >= end) {
                count++;
                end = intervals[i][1];
            }
        }
        return intervals.length - count;
    }
}""",
        "cpp": """class NonOverlappingIntervals {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            return a[1] < b[1];
        });
        int count = 1, end = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= end) {
                count++;
                end = intervals[i][1];
            }
        }
        return intervals.size() - count;
    }
};""",
        "python": """def erase_overlap_intervals(intervals):
    intervals.sort(key=lambda x: x[1])
    count, end = 1, intervals[0][1]
    for i in range(1, len(intervals)):
        if intervals[i][0] >= end:
            count += 1
            end = intervals[i][1]
    return len(intervals) - count"""
    }
]

base_path = "src/data/courses/dsa/greedy"

for lesson in lessons:
    lesson_path = os.path.join(base_path, lesson["section"], lesson["slug"])
    code_path = os.path.join(lesson_path, "code")
    
    os.makedirs(os.path.join(code_path, "java"), exist_ok=True)
    os.makedirs(os.path.join(code_path, "cpp"), exist_ok=True)
    os.makedirs(os.path.join(code_path, "python"), exist_ok=True)
    
    with open(os.path.join(lesson_path, f"{lesson['slug']}.md"), "w", encoding="utf-8") as f:
        f.write(lesson["md"])
    
    json_content = {
        "title": lesson["title"],
        "description": lesson["title"],
        "difficulty": "medium",
        "isPremium": False,
        "isPosted": True
    }
    with open(os.path.join(lesson_path, f"{lesson['slug']}.json"), "w", encoding="utf-8") as f:
        json.dump(json_content, f, indent=4)
    
    class_name = ''.join(word.capitalize() for word in lesson['slug'].split('-'))
    
    with open(os.path.join(code_path, "java", f"{class_name}.java"), "w") as f:
        f.write(lesson["java"])
    
    with open(os.path.join(code_path, "cpp", f"{class_name}.cpp"), "w") as f:
        f.write(lesson["cpp"])
    
    with open(os.path.join(code_path, "python", f"{lesson['slug']}.py"), "w") as f:
        f.write(lesson["python"])

print(f"Created {len(lessons)} greedy lessons (part 1)")
