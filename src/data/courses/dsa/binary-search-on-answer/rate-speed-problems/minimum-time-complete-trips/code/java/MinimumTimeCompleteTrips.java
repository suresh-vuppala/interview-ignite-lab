class Solution {
    public long minimumTime(int[] time, int totalTrips) {
        long lo=1,hi=0; for(int t:time)hi=Math.max(hi,t); hi*=totalTrips;
        while(lo<hi){long mid=lo+(hi-lo)/2,trips=0;for(int t:time)trips+=mid/t;if(trips>=totalTrips)hi=mid;else lo=mid+1;}
        return lo;
    }
}