class Solution {
    public int minDays(int[] bloomDay, int m, int k) {
        if ((long)m*k > bloomDay.length) return -1;
        int lo=1, hi=0; for(int d:bloomDay) hi=Math.max(hi,d);
        while(lo<hi) { int mid=lo+(hi-lo)/2,b=0,f=0; for(int d:bloomDay){if(d<=mid){if(++f==k){b++;f=0;}}else f=0;} if(b>=m)hi=mid;else lo=mid+1; }
        return lo;
    }
}