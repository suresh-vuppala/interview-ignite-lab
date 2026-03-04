class TaskScheduler {
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
};