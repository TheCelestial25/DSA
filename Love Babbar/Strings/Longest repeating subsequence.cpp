int dp[1000][1000];

// This function mainly returns LCS(str, str)
// with a condition that same characters at
// same index are not considered.

int findLongestRepeatingSubSeq(string X, int m, int n)
{
 
if(dp[m][n]!=-1)
return dp[m][n];
 
// return if we have reached the end of either string
if (m == 0 || n == 0)
    return dp[m][n] = 0;

// if characters at index m and n matches
// and index is different
if (X[m - 1] == X[n - 1] && m != n)
    return dp[m][n] = findLongestRepeatingSubSeq(X,
                        m - 1, n - 1) + 1;

// else if characters at index m and n don't match
return dp[m][n] = max (findLongestRepeatingSubSeq(X, m, n - 1),
                       findLongestRepeatingSubSeq(X, m - 1, n));
}
	int LongestRepeatingSubsequence(string str){
	    memset(dp,-1,sizeof(dp));
	    return findLongestRepeatingSubSeq(str, str.length(), str.length());
	}