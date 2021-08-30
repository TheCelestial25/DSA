int getRow(vector<vector<int>>& a, int x) {
    int l = 0, h = a.size() - 1;
    int col = a[0].size();
    while(l<=h) {
        int mid = (l+h) >> 1;
        if(a[mid][0] <= x and a[mid][col-1] >= x) return mid;
        else if(a[mid][0] > x) h = mid - 1;
        else if(a[mid][col-1] < x) l = mid + 1;
    }
    return -1;
}

int getColumn(vector<vector<int>>& a, int x, int row) {
    int l = 0, h = a[0].size() - 1;
    while(l<=h) {
        int mid = (l+h) >> 1;
        if(a[row][mid]==x) return mid;
        else if(a[row][mid] > x) h = mid - 1;
        else l = mid + 1;
    }
    return -1;
}
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = getRow(matrix, target);
    if(row==-1) return false;
    int col = getColumn(matrix, target, row);
    if(col==-1) return false;
    return true;
}