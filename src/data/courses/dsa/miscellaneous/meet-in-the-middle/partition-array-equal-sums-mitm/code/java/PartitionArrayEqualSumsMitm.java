class Solution {
    public boolean canPartition(int[] nums) {
        int total=0; for(int n:nums)total+=n; if(total%2!=0)return false;
        int target=total/2,n1=nums.length,h=n1/2;
        Set<Integer> left=new HashSet<>();
        for(int m=0;m<(1<<h);m++){int s=0;for(int i=0;i<h;i++)if((m&(1<<i))!=0)s+=nums[i];left.add(s);}
        for(int m=0;m<(1<<(n1-h));m++){int s=0;for(int i=0;i<n1-h;i++)if((m&(1<<i))!=0)s+=nums[h+i];if(left.contains(target-s))return true;}
        return false;
    }
}