vector<int> find(int a[], int n , int x )
{
    vector<int> res(2);
    int l=0, r=n-1;
    while(l<=r) {
        int mid = (l+r) >> 1;
        if(a[mid] >= x) r = mid-1;
        else l = mid + 1;
    }
    if(a[l] != x) res[0] = -1;
    else res[0] = l;
    l=0, r=n-1;
    while(l<=r) {
        int mid = (l+r) >> 1;
        if(a[mid] <= x) l = mid + 1;
        else r = mid - 1;
    }
    if(a[r] != x) res[1] = -1;
    else res[1] = r;
    return res;
}