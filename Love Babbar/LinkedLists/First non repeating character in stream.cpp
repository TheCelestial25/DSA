string FirstNonRepeating(string s){
    // Code here
    unordered_map<char, list<char>::iterator> mp;
    set<char> seen;
    list<char> q;
    string res = "";
    for(char c: s) {
        if(seen.find(c) == seen.end()) {
            res += q.front();
            seen.insert(c);
            q.push_back(c);
            mp[c] = q.end();
        } else {
            res += "#";
            q.erase(mp[c]);
        }
    }
    return res;
}