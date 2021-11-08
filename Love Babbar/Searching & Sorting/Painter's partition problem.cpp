bool isValid(int a[], int n, int m, int mid) {
    int count = 1;
    int sum = a[0];
    for(int i=1; i<n; i++) {
        sum += a[i];
        if(sum > mid) {
            sum = a[i];
            count++;
        }
    }
    return count <= m;
}

//Function to find minimum number of pages.
int findPages(int a[], int n, int m) 
{
    //code here
    if(m > n) return -1;
    int l = *max_element(a, a + n);
    int r = 0;
    for(int i=0; i<n; i++) r += a[i];
    int ans = -1;
    while(l<=r) {
        int mid = l + (r-l)/2;
        if(isValid(a, n, m, mid)) {
            ans = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    return ans;
}