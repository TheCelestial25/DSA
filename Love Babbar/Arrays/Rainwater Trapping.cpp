int trappingWater(int a[], int n){
    // Code here
    int l=0, r=n-1, lm = a[0], rm = a[n-1], res = 0;
    while(l<=r) {
        if(a[l]<=a[r]) {
            lm = max(lm, a[l]);
            res += lm - a[l];
            l++;
        }
        else {
            rm = max(rm, a[r]);
            res += rm - a[r];
            r--;
        }
    }
    return res;
}