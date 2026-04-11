class Solution {
    public int minimumTimeRequired(int[] jobs, int k) {
        Arrays.sort(jobs); int lo=jobs[jobs.length-1],hi=0; for(int j:jobs)hi+=j;
        while(lo<hi){int mid=lo+(hi-lo)/2; if(canFinish(jobs,new int[k],jobs.length-1,mid))hi=mid;else lo=mid+1;}
        return lo;
    }
    boolean canFinish(int[] jobs,int[] w,int idx,int lim){
        if(idx<0)return true;
        for(int i=0;i<w.length;i++){if(w[i]+jobs[idx]<=lim){w[i]+=jobs[idx];if(canFinish(jobs,w,idx-1,lim))return true;w[i]-=jobs[idx];}if(w[i]==0)break;}
        return false;
    }
}