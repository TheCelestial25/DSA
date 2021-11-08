int kthElement(int arr1[], int arr2[], int n, int m, int k)
{
    if(n < m) return kthElement(arr2, arr1, m, n, k);
    int l = max(0, k-m), r = min(n, k);
    while(l<=r) {
        int p1 = (l+r) >> 1;
        int p2 = k - p1;
        
        int l1 = p1 > 0 ? arr1[p1-1] : INT_MIN;
        int r1 = p1 < n ? arr1[p1] : INT_MAX;
        
        int l2 = p2 > 0 ? arr2[p2-1] : INT_MIN;
        int r2 = p2 < m ? arr2[p2] : INT_MAX;
        
        if(l1 <= r2 and l2 <= r1) return max(l1, l2);
        else if(l1 > r2) r = p1 - 1;
        else l = p1 + 1;
    }
    return -1;
}