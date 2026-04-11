class Solution {
    public int minSpeedOnTime(int[] dist, double hour) {
        if(dist.length-1>=hour) return -1;
        int lo=1,hi=(int)1e7;
        while(lo<hi){int mid=lo+(hi-lo)/2;double t=0;for(int i=0;i<dist.length-1;i++)t+=(dist[i]+mid-1)/mid;t+=(double)dist[dist.length-1]/mid;if(t<=hour)hi=mid;else lo=mid+1;}
        return lo;
    }
}