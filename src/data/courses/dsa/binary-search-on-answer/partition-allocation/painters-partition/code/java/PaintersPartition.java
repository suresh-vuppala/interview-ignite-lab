// Time: O(N * log(sum - max))
// Space: O(1)

class PaintersPartition {
    public static int paintersPartition(int[] arr, int m) {
        if (m > arr.length) return -1;
        
        int left = getMax(arr), right = getSum(arr), result = right;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canPaint(arr, m, mid)) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return result;
    }
    
    private static boolean canPaint(int[] arr, int m, int maxTime) {
        int painters = 1, currentTime = 0;
        for (int time : arr) {
            if (currentTime + time > maxTime) {
                painters++;
                currentTime = time;
            } else {
                currentTime += time;
            }
        }
        return painters <= m;
    }
    
    private static int getMax(int[] arr) {
        int max = arr[0];
        for (int num : arr) max = Math.max(max, num);
        return max;
    }
    
    private static int getSum(int[] arr) {
        int sum = 0;
        for (int num : arr) sum += num;
        return sum;
    }
}
