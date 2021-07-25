bool subArrayExists(int arr[], int n)
{
    int p[n];
    for(int i=0; i<n; i++) p[i] = 0;
    p[0] = arr[0];
    set<int> s;
    s.insert(p[0]);
    s.insert(0);
    for(int i=1; i<n; i++) {
        p[i] = p[i-1] + arr[i];
        if(s.find(p[i]) != s.end())
            return true;
        s.insert(p[i]);
    }
    return false;
}