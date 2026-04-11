class Solution {
    int[] parent, rank;
    int find(int x) { return parent[x] == x ? x : (parent[x] = find(parent[x])); }
    void union(int a, int b) { a=find(a); b=find(b); if(a!=b){if(rank[a]<rank[b]){int t=a;a=b;b=t;} parent[b]=a; if(rank[a]==rank[b])rank[a]++;} }
    
    public List<List<String>> accountsMerge(List<List<String>> accounts) {
        int n = accounts.size();
        parent = new int[n]; rank = new int[n];
        for (int i = 0; i < n; i++) parent[i] = i;
        Map<String, Integer> emailToId = new HashMap<>();
        for (int i = 0; i < n; i++)
            for (int j = 1; j < accounts.get(i).size(); j++) {
                String email = accounts.get(i).get(j);
                if (emailToId.containsKey(email)) union(i, emailToId.get(email));
                else emailToId.put(email, i);
            }
        Map<Integer, TreeSet<String>> groups = new HashMap<>();
        for (var e : emailToId.entrySet()) groups.computeIfAbsent(find(e.getValue()), k->new TreeSet<>()).add(e.getKey());
        List<List<String>> res = new ArrayList<>();
        for (var e : groups.entrySet()) { List<String> l = new ArrayList<>(); l.add(accounts.get(e.getKey()).get(0)); l.addAll(e.getValue()); res.add(l); }
        return res;
    }
}