bool find3Numbers(int a[], int n, int x)
    {
        //Your Code Here
        sort(a, a+n);
        for(int i=0; i<n; i++) {
            int j = i+1, k = n-1;
            while(j<k) {
                if(a[i]+a[j]+a[k]==x) return true;
                else if(a[i]+a[j]+a[k] < x) j++;
                else k--;
            }
        }
        return false;
    }