class GasStation {
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
}