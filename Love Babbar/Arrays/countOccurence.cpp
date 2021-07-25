int countOccurence(int arr[], int n, int k) {
    // Your code here
    unordered_map<int, int> mp;
    for(int i=0; i<n; i++) mp[arr[i]]++;
    int c = 0;
    for(auto x : mp) {
        if(x.second > n/k) c++;
    }
    return c;
}