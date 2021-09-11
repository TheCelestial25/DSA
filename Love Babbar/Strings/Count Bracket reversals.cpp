int countRev (string s)
{
    // your code here
    if(s.length() % 2 != 0) return -1;
    int l = 0, r = 0, cn = 0;
    for(int i=0; i<s.length(); i++) {
        if(s[i] == '}') r++;
        else l++;
        if(r > l) {
            cn++;
            r--;
            l++;
        }
    }
    return cn + ceil((l - r)/2.00);
}