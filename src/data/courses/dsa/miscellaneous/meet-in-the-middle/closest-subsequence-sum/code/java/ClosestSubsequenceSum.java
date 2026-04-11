class Solution {
    public int minAbsDifference(int[] nums, int goal) {
        int n=nums.length,h=n/2; List<Integer> L=new ArrayList<>(),R=new ArrayList<>();
        for(int m=0;m<(1<<h);m++){int s=0;for(int i=0;i<h;i++)if((m&(1<<i))!=0)s+=nums[i];L.add(s);}
        for(int m=0;m<(1<<(n-h));m++){int s=0;for(int i=0;i<n-h;i++)if((m&(1<<i))!=0)s+=nums[h+i];R.add(s);}
        Collections.sort(R); int best=Integer.MAX_VALUE;
        for(int s:L){int need=goal-s;int idx=Collections.binarySearch(R,need);if(idx<0)idx=-idx-1;
            if(idx<R.size())best=Math.min(best,Math.abs(s+R.get(idx)-goal));
            if(idx>0)best=Math.min(best,Math.abs(s+R.get(idx-1)-goal));}
        return best;
    }
}