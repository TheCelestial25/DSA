vector<vector<int> > fourSum(vector<int> &a, int k) {
        int n = a.size();
        set<vector<int> > res;
        unordered_map<int, set<pair<int, int>>> mp;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) mp[a[i]+a[j]].insert({i, j});
        }
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                int sum = a[i] + a[j];
                if(mp.find(k - sum) != mp.end())  {
                    for(auto x : mp[k-sum]) {
                        if(x.first != i and x.second != i and x.first != j and x.second != j) {
                            vector<int> t = {a[i], a[j], a[x.first], a[x.second]};
                            sort(t.begin(), t.end());
                            res.insert(t);
                        }
                    }
                }
            }
        }
        vector<vector<int> > re;
        for(auto x : res) re.push_back(x);
        // for(auto x : mp) {
        //     cout << x.first << endl;
        //     for(auto y : x.second) cout << y.first << " " << y.second << endl;
        //     cout << endl;
        // }
        return re;