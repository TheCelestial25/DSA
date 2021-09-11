vector<string> res;
void permute(string s, int l) {
    if(l == s.length()-1) {
        res.push_back(s);
        return;
    }
    for(int i=l; i<s.length(); i++) {
        swap(s[l], s[i]);
        permute(s, l+1);
        swap(s[l], s[i]);
    }
}
vector<string>find_permutation(string S)
{
    // Code here there
    permute(S, 0);
    sort(res.begin(), res.end());
    return res;
}