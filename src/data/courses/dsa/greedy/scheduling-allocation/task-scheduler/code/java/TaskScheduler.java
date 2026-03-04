class TaskScheduler {
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
}