class Solution {
    public String reorganizeString(String s) {
        int[] freq = new int[26];
        for (char c : s.toCharArray()) freq[c-'a']++;
        PriorityQueue<int[]> pq = new PriorityQueue<>((a,b)->b[1]-a[1]);
        for (int i=0;i<26;i++) if(freq[i]>0) pq.offer(new int[]{i,freq[i]});
        StringBuilder sb = new StringBuilder();
        while (pq.size()>1) {
            int[] a=pq.poll(), b=pq.poll();
            sb.append((char)(a[0]+'a')); sb.append((char)(b[0]+'a'));
            if(a[1]>1) pq.offer(new int[]{a[0],a[1]-1});
            if(b[1]>1) pq.offer(new int[]{b[0],b[1]-1});
        }
        if(!pq.isEmpty()) { if(pq.peek()[1]>1) return ""; sb.append((char)(pq.poll()[0]+'a')); }
        return sb.toString();
    }
}