int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
    // code here
    int cn = 0, cni = -1;
    for(int i=m-1; i>=0; i--) {
        if(arr[0][i]==0) break;
        cn++;
    }
    if(cn>0) cni = 0;
    for(int i=0; i<n; i++) {
        if(arr[i][m-cn-1]==0) continue;
        else {
            cni = i;
            for(int j=m-cn-1; j>=0; j--) {
                if(arr[i][j]==0) break;
                cn++;
            }
        }
    }
    return cni;
}