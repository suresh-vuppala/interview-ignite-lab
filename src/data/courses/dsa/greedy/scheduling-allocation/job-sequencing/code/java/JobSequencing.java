class JobSequencing {
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
}