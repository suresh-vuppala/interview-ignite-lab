import os
import json

lessons = [
    {
        "section": "interval-based",
        "slug": "merge-intervals",
        "title": "Merge Intervals",
        "md": """## Problem Statement

Merge all overlapping intervals.

## Approach

1. Sort intervals by start time
2. Merge overlapping intervals

## Complexity

- Time: O(n log n)
- Space: O(n)

## Code

```code```""",
        "java": """class MergeIntervals {
    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> a[0] - b[0]);
        List<int[]> result = new ArrayList<>();
        int[] current = intervals[0];
        for (int i = 1; i < intervals.length; i++) {
            if (intervals[i][0] <= current[1]) {
                current[1] = Math.max(current[1], intervals[i][1]);
            } else {
                result.add(current);
                current = intervals[i];
            }
        }
        result.add(current);
        return result.toArray(new int[result.size()][]);
    }
}""",
        "cpp": """class MergeIntervals {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        vector<int> current = intervals[0];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= current[1]) {
                current[1] = max(current[1], intervals[i][1]);
            } else {
                result.push_back(current);
                current = intervals[i];
            }
        }
        result.push_back(current);
        return result;
    }
};""",
        "python": """def merge(intervals):
    intervals.sort()
    result = [intervals[0]]
    for start, end in intervals[1:]:
        if start <= result[-1][1]:
            result[-1][1] = max(result[-1][1], end)
        else:
            result.append([start, end])
    return result"""
    },
    {
        "section": "interval-based",
        "slug": "meeting-rooms-ii",
        "title": "Meeting Rooms II",
        "md": """## Problem Statement

Find minimum number of meeting rooms required.

## Approach

1. Sort start and end times separately
2. Use two pointers to track rooms needed

## Complexity

- Time: O(n log n)
- Space: O(n)

## Code

```code```""",
        "java": """class MeetingRoomsII {
    public int minMeetingRooms(int[][] intervals) {
        int n = intervals.length;
        int[] start = new int[n], end = new int[n];
        for (int i = 0; i < n; i++) {
            start[i] = intervals[i][0];
            end[i] = intervals[i][1];
        }
        Arrays.sort(start);
        Arrays.sort(end);
        
        int rooms = 0, endPtr = 0;
        for (int i = 0; i < n; i++) {
            if (start[i] < end[endPtr]) {
                rooms++;
            } else {
                endPtr++;
            }
        }
        return rooms;
    }
}""",
        "cpp": """class MeetingRoomsII {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> start(n), end(n);
        for (int i = 0; i < n; i++) {
            start[i] = intervals[i][0];
            end[i] = intervals[i][1];
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        
        int rooms = 0, endPtr = 0;
        for (int i = 0; i < n; i++) {
            if (start[i] < end[endPtr]) {
                rooms++;
            } else {
                endPtr++;
            }
        }
        return rooms;
    }
};""",
        "python": """def min_meeting_rooms(intervals):
    start = sorted([i[0] for i in intervals])
    end = sorted([i[1] for i in intervals])
    rooms, end_ptr = 0, 0
    for i in range(len(intervals)):
        if start[i] < end[end_ptr]:
            rooms += 1
        else:
            end_ptr += 1
    return rooms"""
    },
    {
        "section": "scheduling-allocation",
        "slug": "job-sequencing",
        "title": "Job Sequencing with Deadlines",
        "md": """## Problem Statement

Schedule jobs with deadlines to maximize profit.

## Approach

1. Sort jobs by profit (descending)
2. For each job, find latest available slot before deadline

## Complexity

- Time: O(n²)
- Space: O(n)

## Code

```code```""",
        "java": """class JobSequencing {
    public int maxProfit(int[] profit, int[] deadline) {
        int n = profit.length;
        int[][] jobs = new int[n][2];
        for (int i = 0; i < n; i++) {
            jobs[i] = new int[]{profit[i], deadline[i]};
        }
        Arrays.sort(jobs, (a, b) -> b[0] - a[0]);
        
        int maxDeadline = 0;
        for (int d : deadline) maxDeadline = Math.max(maxDeadline, d);
        
        int[] slot = new int[maxDeadline + 1];
        Arrays.fill(slot, -1);
        
        int totalProfit = 0;
        for (int[] job : jobs) {
            for (int j = job[1]; j > 0; j--) {
                if (slot[j] == -1) {
                    slot[j] = job[0];
                    totalProfit += job[0];
                    break;
                }
            }
        }
        return totalProfit;
    }
}""",
        "cpp": """class JobSequencing {
public:
    int maxProfit(vector<int>& profit, vector<int>& deadline) {
        int n = profit.size();
        vector<pair<int, int>> jobs;
        for (int i = 0; i < n; i++) {
            jobs.push_back({profit[i], deadline[i]});
        }
        sort(jobs.begin(), jobs.end(), greater<pair<int, int>>());
        
        int maxDeadline = *max_element(deadline.begin(), deadline.end());
        vector<int> slot(maxDeadline + 1, -1);
        
        int totalProfit = 0;
        for (auto& job : jobs) {
            for (int j = job.second; j > 0; j--) {
                if (slot[j] == -1) {
                    slot[j] = job.first;
                    totalProfit += job.first;
                    break;
                }
            }
        }
        return totalProfit;
    }
};""",
        "python": """def max_profit(profit, deadline):
    jobs = sorted(zip(profit, deadline), reverse=True)
    max_deadline = max(deadline)
    slot = [-1] * (max_deadline + 1)
    total_profit = 0
    for p, d in jobs:
        for j in range(d, 0, -1):
            if slot[j] == -1:
                slot[j] = p
                total_profit += p
                break
    return total_profit"""
    },
    {
        "section": "scheduling-allocation",
        "slug": "task-scheduler",
        "title": "Task Scheduler",
        "md": """## Problem Statement

Schedule tasks with cooling interval n between same tasks.

## Approach

1. Count task frequencies
2. Calculate idle slots needed
3. Fill with most frequent tasks first

## Complexity

- Time: O(n)
- Space: O(1)

## Code

```code```""",
        "java": """class TaskScheduler {
    public int leastInterval(char[] tasks, int n) {
        int[] freq = new int[26];
        for (char task : tasks) freq[task - 'A']++;
        
        Arrays.sort(freq);
        int maxFreq = freq[25];
        int idleSlots = (maxFreq - 1) * n;
        
        for (int i = 24; i >= 0 && idleSlots > 0; i--) {
            idleSlots -= Math.min(maxFreq - 1, freq[i]);
        }
        
        return tasks.length + Math.max(0, idleSlots);
    }
}""",
        "cpp": """class TaskScheduler {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (char task : tasks) freq[task - 'A']++;
        
        sort(freq.begin(), freq.end());
        int maxFreq = freq[25];
        int idleSlots = (maxFreq - 1) * n;
        
        for (int i = 24; i >= 0 && idleSlots > 0; i--) {
            idleSlots -= min(maxFreq - 1, freq[i]);
        }
        
        return tasks.size() + max(0, idleSlots);
    }
};""",
        "python": """def least_interval(tasks, n):
    freq = [0] * 26
    for task in tasks:
        freq[ord(task) - ord('A')] += 1
    
    freq.sort()
    max_freq = freq[25]
    idle_slots = (max_freq - 1) * n
    
    for i in range(24, -1, -1):
        if idle_slots <= 0:
            break
        idle_slots -= min(max_freq - 1, freq[i])
    
    return len(tasks) + max(0, idle_slots)"""
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

print(f"Created {len(lessons)} greedy lessons (part 2)")
