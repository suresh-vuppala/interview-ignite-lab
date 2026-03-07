// Time: O(n log(m * k)), Space: O(1)

class MinimumTimeCompleteTrips {
    public long minimumTime(int[] time, int totalTrips) {
        long left = 1, right = (long) Arrays.stream(time).min().getAsInt() * totalTrips;
        
        while (left <= right) {
            long mid = left + (right - left) / 2;
            long trips = 0;
            for (int t : time) trips += mid / t;
            
            if (trips >= totalTrips) right = mid - 1;
            else left = mid + 1;
        }
        
        return left;
    }
}
