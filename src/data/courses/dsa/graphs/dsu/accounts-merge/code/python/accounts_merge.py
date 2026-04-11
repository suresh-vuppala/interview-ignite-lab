class Solution:
    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
        parent = list(range(len(accounts)))
        def find(x):
            while parent[x] != x: parent[x] = parent[parent[x]]; x = parent[x]
            return x
        def union(a, b): parent[find(a)] = find(b)
        
        email_to_id = {}
        for i, acc in enumerate(accounts):
            for email in acc[1:]:
                if email in email_to_id: union(i, email_to_id[email])
                else: email_to_id[email] = i
        
        from collections import defaultdict
        groups = defaultdict(set)
        for email, idx in email_to_id.items(): groups[find(idx)].add(email)
        return [[accounts[i][0]] + sorted(emails) for i, emails in groups.items()]