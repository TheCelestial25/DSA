long long maxProduct(int *arr, int n) {
    // code here
    int mn = arr[0], mx = arr[0], ans=arr[0];
    for(int i=1; i<n; i++) {
        int temp = mx;
        mx = max({arr[i]*mx, arr[i], arr[i]*mn});
        mn = min({arr[i]*temp, arr[i], arr[i]*mn});
        ans = max(ans, mx);
    }
    return ans*1LL;
}