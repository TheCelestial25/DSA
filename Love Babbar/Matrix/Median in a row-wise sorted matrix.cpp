int countLessThanEqual(vector<vector<int>> &a, int r, int x) {
    int l = 0, h = a[0].size()-1;
    while(l<=h) {
        int mid = l + (h-l)/2;
        if(a[r][mid] <= x) l = mid + 1;
        else h = mid - 1;
    }
    return h+1;
}
int median(vector<vector<int>> &matrix, int r, int c){
    // code here          
    int l = 1, h = 1e9;
    int mid;
    while(l <= h) {
        mid = l + (h-l)/2;
        int cn = 0;
        for(int i=0; i<r; i++) cn += countLessThanEqual(matrix, i, mid);
        if(cn <= (r*c)/2) l = mid + 1;
        else h = mid - 1;
    }
    return h+1;
}