class Solution {
    // O(n + m) time — Frequency map approach
    public int[] intersect(int[] nums1, int[] nums2) {
        Map<Integer, Integer> freq = new HashMap<>();
        for (int n : nums1) freq.merge(n, 1, Integer::sum);
        
        List<Integer> result = new ArrayList<>();
        for (int n : nums2) {
            if (freq.getOrDefault(n, 0) > 0) {
                result.add(n);
                freq.merge(n, -1, Integer::sum);
            }
        }
        return result.stream().mapToInt(i -> i).toArray();
    }
}