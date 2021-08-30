vector<int> spirallyTraverse(vector<vector<int> > a, int r, int c) 
{
    vector<int> res;
    int cn=0;
    int up = 0, down = r - 1, left = 0, right = c - 1;
    while(cn<r*c) {
        if(cn<r*c) for(int i=left; i<=right; i++) {res.push_back(a[up][i]);cn++;}
        if(cn<r*c) for(int i=up+1; i<=down; i++) {res.push_back(a[i][right]);cn++;}
        if(cn<r*c) for(int i=right-1; i>=left; i--) {res.push_back(a[down][i]);cn++;}
        if(cn<r*c) for(int i=down-1; i>up; i--) {res.push_back(a[i][left]);cn++;}
        left++;
        right--;
        up++;
        down--;
    }
    return res;
}