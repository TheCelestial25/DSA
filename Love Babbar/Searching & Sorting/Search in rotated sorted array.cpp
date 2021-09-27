int search(vector<int>& a, int target) {
    int por = 0;
    int l = 0, r = a.size()-1, n=a.size();
    while(l<=r) {
        int mid = (l+r)>>1;
        cout << mid << endl;  
        if(mid < n-1  and a[mid]>a[mid+1]) {
            por = mid+1;
            break;
        }
        else if(a[mid] >= a[0]) l = mid + 1;
        else r = mid - 1;
    }
    // cout << por << endl;
    l=0;
    r=n-1;
    while(l<=r) {
        int mid = (l+r) >> 1;
        int emid = (mid+por)%n;
        if(a[emid] == target) return emid;
        else if(a[emid] > target) r = mid - 1;
        else l = mid + 1;
    }
    return -1;
}