class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        List<Integer> res = new ArrayList<>(); if (s.length()<p.length()) return res;
        int[] pf=new int[26], wf=new int[26]; for (char c:p.toCharArray()) pf[c-'a']++;
        for (int i=0;i<s.length();i++) {
            wf[s.charAt(i)-'a']++;
            if (i>=p.length()) wf[s.charAt(i-p.length())-'a']--;
            if (Arrays.equals(wf,pf)) res.add(i-p.length()+1);
        } return res;
    }
}