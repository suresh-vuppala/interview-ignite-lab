class Solution {
    public int[] intersect(int[] a, int[] b) {
        Map<Integer,Integer> freq = new HashMap<>();
        for (int n : a) freq.merge(n, 1, Integer::sum);
        List<Integer> res = new ArrayList<>();
        for (int n : b) if (freq.getOrDefault(n,0)>0) { res.add(n); freq.merge(n,-1,Integer::sum); }
        return res.stream().mapToInt(x->x).toArray();
    }
}