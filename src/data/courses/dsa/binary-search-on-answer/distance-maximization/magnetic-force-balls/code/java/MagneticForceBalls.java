class Solution {
    public int maxDistance(int[] pos, int m) {
        Arrays.sort(pos); int lo=1,hi=pos[pos.length-1]-pos[0];
        while(lo<hi){int mid=lo+(hi-lo+1)/2,cnt=1,last=pos[0]; for(int i=1;i<pos.length;i++) if(pos[i]-last>=mid){cnt++;last=pos[i];} if(cnt>=m)lo=mid;else hi=mid-1;}
        return lo;
    }
}