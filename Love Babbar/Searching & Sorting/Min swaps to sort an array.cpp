int minSwaps(vector<int>&nums)
{
    int n = nums.size();
    vector<pair<int, int>> v(n);
    for(int i=0; i<n; i++) {
        v[i].first = nums[i];
        v[i].second = i;
    }
    sort(v.begin(), v.end());
    vector<bool> visited(n, false);
    int ans = 0;
    for(int i=0; i<n; i++) {
        if(visited[i] or v[i].second == i) continue;
        int cycle_size = 0;
        int j = i;
        while(!visited[j]) {
            visited[j] = true;
            cycle_size++;
            j = v[j].second;
        }
        if(cycle_size > 0) {
            ans += cycle_size - 1;
        }
    }
    return ans;
}