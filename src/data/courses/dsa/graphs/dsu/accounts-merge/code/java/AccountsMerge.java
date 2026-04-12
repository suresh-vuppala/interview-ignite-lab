// ============================================================
// Accounts Merge
// ============================================================
import java.util.*;
class Solution {
    int[] pa; int find(int x){return pa[x]==x?x:(pa[x]=find(pa[x]));}
    void unite(int x,int y){int a=find(x),b=find(y);if(a!=b)pa[b]=a;}
    public List<List<String>> accountsMerge(List<List<String>> accounts) {
        Map<String,Integer> emailId = new HashMap<>(); int id = 0;
        Map<String,String> emailName = new HashMap<>();
        for (var acc : accounts) for (int i=1;i<acc.size();i++) {
            if (!emailId.containsKey(acc.get(i))) emailId.put(acc.get(i), id++);
            emailName.put(acc.get(i), acc.get(0));
        }
        pa = new int[id]; for (int i=0;i<id;i++) pa[i]=i;
        for (var acc : accounts) for (int i=2;i<acc.size();i++) unite(emailId.get(acc.get(1)),emailId.get(acc.get(i)));
        Map<Integer,List<String>> groups = new HashMap<>();
        for (var e : emailId.entrySet()) groups.computeIfAbsent(find(e.getValue()),k->new ArrayList<>()).add(e.getKey());
        List<List<String>> result = new ArrayList<>();
        for (var g : groups.values()) { Collections.sort(g); g.add(0,emailName.get(g.get(0))); result.add(g); }
        return result;
    }
}
