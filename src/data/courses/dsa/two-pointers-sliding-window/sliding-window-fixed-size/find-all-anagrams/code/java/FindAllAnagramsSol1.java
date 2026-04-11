class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        List<Integer> res = new ArrayList<>(); int m=p.length();
        int[] pf = new int[26]; for (char c:p.toCharArray()) pf[c-'a']++;
        for (int i=0;i<=s.length()-m;i++) {
            int[] wf = new int[26]; for (int j=i;j<i+m;j++) wf[s.charAt(j)-'a']++;
            if (Arrays.equals(wf,pf)) res.add(i);
        } return res;
    }
}