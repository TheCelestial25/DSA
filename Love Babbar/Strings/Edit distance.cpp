int editDistance(string s, string t) {
    // Code here
    vector<vector<int>> dp(s.length()+1, vector<int>(t.length()+1, 0));
    for(int i=0; i<=s.length(); i++) {
        for(int j=0; j<=t.length(); j++) {
            if (i == 0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i;
            else if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1];
            else {
                dp[i][j] = 1 + min({
                    dp[i][j-1], // add
                    dp[i-1][j], // remove
                    dp[i-1][j-1] // replace
                });   
            }
        }
    }
    return dp[s.length()][t.length()];
}