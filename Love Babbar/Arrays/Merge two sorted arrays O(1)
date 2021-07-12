int getGap(int gap) {
    if(gap<=1) return 0;
    return ceil(gap/2.00);
}
void merge(int a[], int b[], int n, int m) {
    // code here
    int gap = getGap(n+m);
    while(gap > 0) {
        int i, j;
        for(i=0; i+gap<n; i++) {
            if(a[i]>a[i+gap])
                swap(a[i], a[i+gap]);
        }
        
        for(j = gap > n ? gap - n : 0; i<n and j<m; j++, i++) {
            if(a[i]>b[j])
                swap(a[i], b[j]);
        }
        for(j=0; j+gap<m; j++) {
            if(b[j]>b[j+gap])
                swap(b[j], b[j+gap]);
        }
        gap = getGap(gap);
    }
}