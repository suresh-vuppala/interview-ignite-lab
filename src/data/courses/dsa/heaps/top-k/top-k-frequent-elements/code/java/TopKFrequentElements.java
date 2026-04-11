class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer,Integer> freq = new HashMap<>();
        for (int n : nums) freq.merge(n, 1, Integer::sum);
        List<Integer>[] buckets = new List[nums.length+1];
        for (var e : freq.entrySet()) { if(buckets[e.getValue()]==null)buckets[e.getValue()]=new ArrayList<>(); buckets[e.getValue()].add(e.getKey()); }
        int[] res = new int[k]; int idx = 0;
        for (int i=buckets.length-1; i>=0 && idx<k; i--) if(buckets[i]!=null) for(int n:buckets[i]) { res[idx++]=n; if(idx==k)break; }
        return res;
    }
}