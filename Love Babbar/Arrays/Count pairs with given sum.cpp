int getPairsCount(int arr[], int n, int k) {
    // code here
    unordered_map<int, int> mp;
    int c=0;
    for(int i=0; i<n; i++) {
        if(arr[i] > k) continue;
        int x = k - arr[i];
        if(mp.find(x) != mp.end()) c += mp[x];
        mp[arr[i]]++;
    }
    return c;
}