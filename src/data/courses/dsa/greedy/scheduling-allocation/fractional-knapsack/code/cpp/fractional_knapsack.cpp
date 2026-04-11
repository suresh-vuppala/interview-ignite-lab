// O(n log n) — Sort by value/weight ratio, take greedily
double fractionalKnapsack(int W, vector<pair<int,int>>& items) {
    // Sort by value/weight ratio descending
    sort(items.begin(), items.end(), [](auto& a, auto& b) {
        return (double)a.first/a.second > (double)b.first/b.second;
    });
    double totalValue = 0;
    for (auto& [val, wt] : items) {
        if (W >= wt) { totalValue += val; W -= wt; } // Take entire item
        else { totalValue += val * ((double)W / wt); break; } // Take fraction
    }
    return totalValue;
}