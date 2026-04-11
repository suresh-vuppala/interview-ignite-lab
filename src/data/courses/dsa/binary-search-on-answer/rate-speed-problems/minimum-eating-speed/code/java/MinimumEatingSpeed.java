class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        int lo=1,hi=0; for(int p:piles)hi=Math.max(hi,p);
        while(lo<hi){int mid=lo+(hi-lo)/2;long hrs=0;for(int p:piles)hrs+=(p+mid-1)/mid;if(hrs<=h)hi=mid;else lo=mid+1;}
        return lo;
    }
}