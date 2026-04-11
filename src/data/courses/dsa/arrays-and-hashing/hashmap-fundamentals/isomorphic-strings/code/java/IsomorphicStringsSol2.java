class Solution {
    // Pattern Encode: O(n) — Compare first-occurrence patterns
    public boolean isIsomorphic(String s, String t) {
        return encode(s).equals(encode(t));
    }
    private String encode(String str) {
        Map<Character,Integer> first = new HashMap<>();
        StringBuilder sb = new StringBuilder();
        for (char c : str.toCharArray()) {
            first.putIfAbsent(c, first.size());
            sb.append(first.get(c)).append(',');
        }
        return sb.toString();
    }
}