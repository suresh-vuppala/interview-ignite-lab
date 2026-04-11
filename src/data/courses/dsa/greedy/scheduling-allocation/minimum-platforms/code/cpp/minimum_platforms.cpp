// O(n log n) — Sort arrivals and departures, sweep line
int minPlatforms(vector<int>& arr, vector<int>& dep) {
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());
    int platforms = 0, maxPlatforms = 0;
    int i = 0, j = 0, n = arr.size();
    while (i < n) {
        if (arr[i] <= dep[j]) { platforms++; i++; }
        else { platforms--; j++; }
        maxPlatforms = max(maxPlatforms, platforms);
    }
    return maxPlatforms;
}