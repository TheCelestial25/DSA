string smallestWindow (string s, string t)
{
    if(t.length() > s.length())
        return "";
    unordered_map<char, int> smp, tmp;
    for(char c : t) tmp[c]++;
    int end = 0, start = 0, req = t.length(), curr = 0, mx = INT_MAX, ans_start = -1;
    while(end < s.length()) {
        char c1 = s[end];
        smp[c1]++;
        if(tmp[c1] != 0 and smp[c1] <= tmp[c1]) curr++;
        if(curr == req) {
            while(tmp[s[start]] == 0 or smp[s[start]] > tmp[s[start]]) {
                if(smp[s[start]] > tmp[s[start]]) smp[s[start]]--; // This while loop can be running because of the second or condition as well, decreasing the map count in that case will make the value negative               
                start++;
            }
            int len = end - start + 1;
            if(len < mx) {
                mx = len;
                ans_start = start;
            }
        }
        end++;
    }
    if(ans_start == -1) return "-1";
    return s.substr(ans_start, mx);
}