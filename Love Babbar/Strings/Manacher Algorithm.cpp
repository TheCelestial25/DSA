string getManacherString(string s) {
    string r = "";
    r.push_back('$');
    r.push_back('#');
    for(int i=0; i<s.length(); i++) {
        r.push_back(s[i]);
        r.push_back('#');
    }
    r.push_back('@');
    return r;
}
string longestPalin (string str) {
    string pre = getManacherString(str);
    int N = pre.size();
    vector<int> p(N+1, 0);
    int C=0, R=0, ans = 0, ansi = 0;
    for(int i=1; i<N-1; i++) {
        int mirror = 2*C - i;
        if(i < R) p[i] = min(R-i, p[mirror]);
        while(pre[i + (1 + p[i])] == pre[i - (1 + p[i])]) p[i]++;
        if(i + p[i] > R) {
            C = i;
            R = i + p[i];
        }
    }
    for(int i=0; i<N; i++) {
        if(p[i] > ans) {
            ans = p[i];
            ansi = i;
        }
    }
    int start = (ansi - 1 - ans)/2;
    int end = (ansi - 1 + ans)/2;
    return str.substr(start, end - start);
}