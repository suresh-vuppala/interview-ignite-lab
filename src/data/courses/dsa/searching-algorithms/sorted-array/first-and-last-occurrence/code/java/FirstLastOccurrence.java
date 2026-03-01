public class FirstLastOccurrence {
    public static int findFirst(int[] arr, int target) {
        int low = 0, high = arr.length - 1;
        int boundary = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == target) {
                boundary = mid;
                high = mid - 1;
            } else if (arr[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return boundary;
    }

    public static int findLast(int[] arr, int target) {
        int low = 0, high = arr.length - 1;
        int boundary = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == target) {
                boundary = mid;
                low = mid + 1;
            } else if (arr[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return boundary;
    }

    public static int[] searchRange(int[] nums, int target) {
        return new int[]{findFirst(nums, target), findLast(nums, target)};
    }
}