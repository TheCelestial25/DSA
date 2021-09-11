int maxHist(int a[], int n) {
    stack<int> s;
    int i = 0, ans = 0;
    while(i < n) {
        if(s.empty() or a[s.top()] <= a[i]) {
            s.push(i++);
        }
        else {
            int tp = s.top();
            s.pop();
            int ta
            rea = a[tp] * (s.empty() ? i :
                                   i - s.top() - 1);
            ans = max(ans, tarea);
        }
    }
    while(!s.empty()) {
        int tp = s.top();
        s.pop();
        int tarea = a[tp]*(s.empty() ? i : s.top() - i - 1);
        ans = max(ans, tarea);
    }
    return ans;
}
int maxArea(int a[MAX][MAX], int n, int m) {
    // Your code here
    int ans = 0;
    for(int i=1; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(a[i][j]==1) {
                a[i][j] += a[i-1][j];
            }
        }
    }
    for(int i=0; i<n; i++) ans = max(ans, maxHist(a[i], m));
    return ans;
}