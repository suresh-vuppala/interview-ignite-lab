class Solution {
    public String alienOrder(String[] words) {
        Map<Character,Set<Character>> adj = new HashMap<>(); Map<Character,Integer> indeg = new HashMap<>();
        for (String w : words) for (char c : w.toCharArray()) { adj.putIfAbsent(c,new HashSet<>()); indeg.putIfAbsent(c,0); }
        for (int i=0;i<words.length-1;i++) { String w1=words[i],w2=words[i+1]; int len=Math.min(w1.length(),w2.length());
            if (w1.length()>w2.length()&&w1.substring(0,len).equals(w2.substring(0,len))) return "";
            for (int j=0;j<len;j++) if (w1.charAt(j)!=w2.charAt(j)) { if (adj.get(w1.charAt(j)).add(w2.charAt(j))) indeg.merge(w2.charAt(j),1,Integer::sum); break; } }
        Queue<Character> q = new LinkedList<>(); for (var e:indeg.entrySet()) if(e.getValue()==0) q.offer(e.getKey());
        StringBuilder sb = new StringBuilder(); while(!q.isEmpty()){char c=q.poll();sb.append(c); for(char nb:adj.get(c))if(indeg.merge(nb,-1,Integer::sum)==0)q.offer(nb);}
        return sb.length()==indeg.size()?sb.toString():"";
    }
}