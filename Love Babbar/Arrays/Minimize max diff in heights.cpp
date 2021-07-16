int getMinDiff(int a[], int n, int k) {
        // code here
        sort(a, a+n);
        int ans = a[n-1] - a[0];
        for(int i=0; i<n-1; i++) {
            int mn = min(a[0]+k, a[i+1]-k);
            int mx = max(a[i]+k, a[n-1]-k);
            if(mn<0) continue;
            ans = min(ans, mx-mn);
        }
        return ans;
    }