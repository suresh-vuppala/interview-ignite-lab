import os

base = "src/data/courses/dsa/greedy"

# Meeting Rooms II
meeting_java = """class MeetingRoomsII {
    public int minMeetingRooms(int[][] intervals) {
        int n = intervals.length;
        int[] start = new int[n], end = new int[n];
        for (int i = 0; i < n; i++) {
            start[i] = intervals[i][0];
            end[i] = intervals[i][1];
        }
        Arrays.sort(start); // Sort start times
        Arrays.sort(end); // Sort end times
        
        int rooms = 0, endPtr = 0;
        for (int i = 0; i < n; i++) {
            if (start[i] < end[endPtr]) { // Meeting starts before earliest ends
                rooms++; // Need new room
            } else {
                endPtr++; // Reuse room
            }
        }
        return rooms;
    }
}"""

meeting_cpp = """class MeetingRoomsII {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> start(n), end(n);
        for (int i = 0; i < n; i++) {
            start[i] = intervals[i][0];
            end[i] = intervals[i][1];
        }
        sort(start.begin(), start.end()); // Sort start times
        sort(end.begin(), end.end()); // Sort end times
        
        int rooms = 0, endPtr = 0;
        for (int i = 0; i < n; i++) {
            if (start[i] < end[endPtr]) { // Meeting starts before earliest ends
                rooms++; // Need new room
            } else {
                endPtr++; // Reuse room
            }
        }
        return rooms;
    }
};"""

meeting_python = """def min_meeting_rooms(intervals):
    start = sorted([i[0] for i in intervals])  # Sort start times
    end = sorted([i[1] for i in intervals])  # Sort end times
    rooms, end_ptr = 0, 0
    for i in range(len(intervals)):
        if start[i] < end[end_ptr]:  # Meeting starts before earliest ends
            rooms += 1  # Need new room
        else:
            end_ptr += 1  # Reuse room
    return rooms"""

# Job Sequencing
job_java = """class JobSequencing {
    public int maxProfit(int[] profit, int[] deadline) {
        int n = profit.length;
        int[][] jobs = new int[n][2];
        for (int i = 0; i < n; i++) {
            jobs[i] = new int[]{profit[i], deadline[i]};
        }
        Arrays.sort(jobs, (a, b) -> b[0] - a[0]); // Sort by profit descending
        
        int maxDeadline = 0;
        for (int d : deadline) maxDeadline = Math.max(maxDeadline, d);
        
        int[] slot = new int[maxDeadline + 1];
        Arrays.fill(slot, -1);
        
        int totalProfit = 0;
        for (int[] job : jobs) {
            for (int j = job[1]; j > 0; j--) { // Find latest available slot
                if (slot[j] == -1) {
                    slot[j] = job[0];
                    totalProfit += job[0];
                    break;
                }
            }
        }
        return totalProfit;
    }
}"""

job_cpp = """class JobSequencing {
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
};"""

job_python = """def max_profit(profit, deadline):
    jobs = sorted(zip(profit, deadline), reverse=True)  # Sort by profit descending
    max_deadline = max(deadline)
    slot = [-1] * (max_deadline + 1)
    total_profit = 0
    for p, d in jobs:
        for j in range(d, 0, -1):  # Find latest available slot
            if slot[j] == -1:
                slot[j] = p
                total_profit += p
                break
    return total_profit"""

# Task Scheduler
task_java = """class TaskScheduler {
    public int leastInterval(char[] tasks, int n) {
        int[] freq = new int[26];
        for (char task : tasks) freq[task - 'A']++;
        
        Arrays.sort(freq);
        int maxFreq = freq[25]; // Most frequent task
        int idleSlots = (maxFreq - 1) * n; // Idle slots needed
        
        for (int i = 24; i >= 0 && idleSlots > 0; i--) {
            idleSlots -= Math.min(maxFreq - 1, freq[i]); // Fill idle slots
        }
        
        return tasks.length + Math.max(0, idleSlots);
    }
}"""

task_cpp = """class TaskScheduler {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (char task : tasks) freq[task - 'A']++;
        
        sort(freq.begin(), freq.end());
        int maxFreq = freq[25]; // Most frequent task
        int idleSlots = (maxFreq - 1) * n; // Idle slots needed
        
        for (int i = 24; i >= 0 && idleSlots > 0; i--) {
            idleSlots -= min(maxFreq - 1, freq[i]); // Fill idle slots
        }
        
        return tasks.size() + max(0, idleSlots);
    }
};"""

task_python = """def least_interval(tasks, n):
    freq = [0] * 26
    for task in tasks:
        freq[ord(task) - ord('A')] += 1
    
    freq.sort()
    max_freq = freq[25]  # Most frequent task
    idle_slots = (max_freq - 1) * n  # Idle slots needed
    
    for i in range(24, -1, -1):
        if idle_slots <= 0:
            break
        idle_slots -= min(max_freq - 1, freq[i])  # Fill idle slots
    
    return len(tasks) + max(0, idle_slots)"""

# Gas Station
gas_java = """class GasStation {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int total = 0, current = 0, start = 0;
        for (int i = 0; i < gas.length; i++) {
            total += gas[i] - cost[i]; // Total gas balance
            current += gas[i] - cost[i]; // Current gas balance
            if (current < 0) { // Can't reach next station
                start = i + 1; // Try starting from next station
                current = 0;
            }
        }
        return total >= 0 ? start : -1; // If total >= 0, solution exists
    }
}"""

gas_cpp = """class GasStation {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0, current = 0, start = 0;
        for (int i = 0; i < gas.size(); i++) {
            total += gas[i] - cost[i]; // Total gas balance
            current += gas[i] - cost[i]; // Current gas balance
            if (current < 0) { // Can't reach next station
                start = i + 1; // Try starting from next station
                current = 0;
            }
        }
        return total >= 0 ? start : -1; // If total >= 0, solution exists
    }
};"""

gas_python = """def can_complete_circuit(gas, cost):
    total, current, start = 0, 0, 0
    for i in range(len(gas)):
        total += gas[i] - cost[i]  # Total gas balance
        current += gas[i] - cost[i]  # Current gas balance
        if current < 0:  # Can't reach next station
            start = i + 1  # Try starting from next station
            current = 0
    return start if total >= 0 else -1  # If total >= 0, solution exists"""

# Write files
with open(f"{base}/interval-based/meeting-rooms-ii/code/java/MeetingRoomsII.java", "w") as f:
    f.write(meeting_java)
with open(f"{base}/interval-based/meeting-rooms-ii/code/cpp/MeetingRoomsII.cpp", "w") as f:
    f.write(meeting_cpp)
with open(f"{base}/interval-based/meeting-rooms-ii/code/python/meeting-rooms-ii.py", "w") as f:
    f.write(meeting_python)

with open(f"{base}/scheduling-allocation/job-sequencing/code/java/JobSequencing.java", "w") as f:
    f.write(job_java)
with open(f"{base}/scheduling-allocation/job-sequencing/code/cpp/JobSequencing.cpp", "w") as f:
    f.write(job_cpp)
with open(f"{base}/scheduling-allocation/job-sequencing/code/python/job-sequencing.py", "w") as f:
    f.write(job_python)

with open(f"{base}/scheduling-allocation/task-scheduler/code/java/TaskScheduler.java", "w") as f:
    f.write(task_java)
with open(f"{base}/scheduling-allocation/task-scheduler/code/cpp/TaskScheduler.cpp", "w") as f:
    f.write(task_cpp)
with open(f"{base}/scheduling-allocation/task-scheduler/code/python/task-scheduler.py", "w") as f:
    f.write(task_python)

with open(f"{base}/scheduling-allocation/gas-station/code/java/GasStation.java", "w") as f:
    f.write(gas_java)
with open(f"{base}/scheduling-allocation/gas-station/code/cpp/GasStation.cpp", "w") as f:
    f.write(gas_cpp)
with open(f"{base}/scheduling-allocation/gas-station/code/python/gas-station.py", "w") as f:
    f.write(gas_python)

print("Greedy lessons part 2 updated with comments")
