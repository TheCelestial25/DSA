int doUnion(int a[], int n, int b[], int m)  {
    //code here
    vector<int> v;
    sort(a, a+n);
    sort(b, b+m);
    int i=0, j=0;
    while(i<n and j<m) {
        while(i<n-1 and a[i]==a[i+1]) i++;
        while(j<m-1 and b[j]==b[j+1]) j++; 
        if(a[i]==b[j]) {
            v.push_back(a[i]);
            i++;
            j++;
        }
        else if(a[i]<b[j]) {
            v.push_back(a[i++]);
        }
        else {
            v.push_back(b[j++]);
        }
    }
    while(i<n) {
    	while(i<n-1 and a[i]==a[i+1]) i++;
        v.push_back(a[i++]);
    }
    while(j<m) {
    	while(j<m-1 and b[j]==b[j+1]) j++;
        v.push_back(b[j++]);
    }
    // for(auto x : v) cout << x << " ";
    // cout << endl;
    return v.size();
}