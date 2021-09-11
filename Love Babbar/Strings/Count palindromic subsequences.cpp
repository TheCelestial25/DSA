vector<vector<int>> dp;
int ps(string s, int i, int j) {
    if(i>j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    if(i==j) return dp[i][j] = 1;
    if(s[i] == s[j]) return dp[i][j] = ps(s, i+1, j) + ps(s, i, j-1) + 1;
    return dp[i][j] = ps(s, i+1, j) + ps(s, i, j-1) - ps(s, i+1, j-1);
}
long long int  countPS(string str)
{
   dp.resize(str.length()+1, vector<int>(str.length()+1, -1));
   return ps(str, 0, str.length() - 1);
}