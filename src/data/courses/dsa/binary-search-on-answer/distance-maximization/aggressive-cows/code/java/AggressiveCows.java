class Solution {
    public int aggressiveCows(int[] stalls, int k) {
        Arrays.sort(stalls);
        int lo=1, hi=stalls[stalls.length-1]-stalls[0];
        while(lo<hi){ int mid=lo+(hi-lo+1)/2,cnt=1,last=stalls[0];
            for(int i=1;i<stalls.length;i++) if(stalls[i]-last>=mid){cnt++;last=stalls[i];}
            if(cnt>=k)lo=mid;else hi=mid-1; }
        return lo;
    }
}