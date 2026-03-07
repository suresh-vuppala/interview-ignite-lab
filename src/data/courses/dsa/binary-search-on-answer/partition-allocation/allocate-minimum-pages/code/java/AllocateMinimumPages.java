// Time: O(N * log(sum - max))
// Space: O(1)

class AllocateMinimumPages {
    public static int allocateBooks(int[] arr, int m) {
        if (m > arr.length) return -1;
        
        int left = getMax(arr), right = getSum(arr);
        int result = right;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canAllocate(arr, m, mid)) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return result;
    }
    
    private static boolean canAllocate(int[] arr, int m, int maxPages) {
        int students = 1, currentPages = 0;
        
        for (int pages : arr) {
            if (currentPages + pages > maxPages) {
                students++;
                currentPages = pages;
            } else {
                currentPages += pages;
            }
        }
        
        return students <= m;
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
