# ============================================================
# Accounts Merge
# ============================================================
from collections import defaultdict
class Solution:
    def accountsMerge(self, accounts):
        parent = {}
        def find(x):
            parent.setdefault(x, x)
            if parent[x] != x: parent[x] = find(parent[x])
            return parent[x]
        def union(x, y):
            parent[find(x)] = find(y)
        email_name = {}
        for acc in accounts:
            for email in acc[1:]:
                email_name[email] = acc[0]
                union(acc[1], email)  # Chain union through first email
        groups = defaultdict(list)
        for email in email_name:
            groups[find(email)].append(email)
        return [[email_name[emails[0]]] + sorted(emails) for emails in groups.values()]
