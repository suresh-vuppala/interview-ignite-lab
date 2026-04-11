class Solution {
    public int[] intersect(int[] a, int[] b) {
        Arrays.sort(a); Arrays.sort(b);
        List<Integer> res = new ArrayList<>();
        int i=0, j=0;
        while (i<a.length && j<b.length) {
            if (a[i]==b[j]) { res.add(a[i]); i++; j++; }
            else if (a[i]<b[j]) i++; else j++;
        }
        return res.stream().mapToInt(x->x).toArray();
    }
}