class Solution {
    public int closestSubsetSum(int[] nums, int target) {
        int n=nums.length, half=n/2;
        List<Integer> left=new ArrayList<>(), right=new ArrayList<>();
        for(int m=0;m<(1<<half);m++){int s=0;for(int i=0;i<half;i++)if((m&(1<<i))!=0)s+=nums[i];left.add(s);}
        for(int m=0;m<(1<<(n-half));m++){int s=0;for(int i=0;i<n-half;i++)if((m&(1<<i))!=0)s+=nums[half+i];right.add(s);}
        Collections.sort(right); int best=Integer.MAX_VALUE;
        for(int s:left){int need=target-s;int idx=Collections.binarySearch(right,need);if(idx<0)idx=-idx-1;
            if(idx<right.size())best=Math.min(best,Math.abs(s+right.get(idx)-target));
            if(idx>0)best=Math.min(best,Math.abs(s+right.get(idx-1)-target));}
        return best;
    }
}