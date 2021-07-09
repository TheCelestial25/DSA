#include <bits/stdc++.h>
using namespace std;

int dp[1000][1000] = {0};

// Longest Common Subsequence
int LCS(string a, string b, int n, int m) {
	if(n==0 or m==0) return 0;
	if(dp[n][m] != -1) return dp[n][m];
	if(a[n-1] == b[m-1]) return dp[n][m] = 1 + LCS(a,b,n-1,m-1);
	else return dp[n][m] = max(LCS(a,b,n-1,m), LCS(a,b,n,m-1));
}

int LCSubstring(string a, string b, int n, int m, int &ans)    //our function return value of (n,m) state
{                        // so that we can use the result in (n+1,m+1) state
  if(n == 0 || m == 0) return 0;   //in case of match in (n+1,m+1) state
  if(dp[n][m] != -1) return dp[n][m];

  LCSubstring(a,b,n-1,m, ans);          //to visit all n*m states          (try example:  X:ASDF
  LCSubstring(a,b,n,m-1, ans);          // we call these states first                     Y:ASDFF)

  if(a[n-1] == b[m-1])
  {

    dp[n][m] =  LCSubstring(a,b,n-1,m-1, ans) + 1;
    ans = max(ans, dp[n][m]);
    return dp[n][m];
  }
    return dp[n][m] = 0;
}


// Print LCS, need to use bottom up approach for this, tried recursion but failed
string printLCS(string a, string b) {
	int n = a.size();
	int m = b.size();

	// Initialization
	for(int i=0; i<=n; i++) dp[i][0] = 0;
	for(int j=0; j<=m; j++) dp[0][j] = 0;

	// Fill up table bottom up, this is required for printing
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			if(a[i-1] == b[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}

	// We can print LCS now that the table is filled
	int i=n, j=m;
	string res;
	while(i>0 and j>0) {
		if(a[i-1] == b[j-1]) {
			res.push_back(a[i-1]);
			i--;
			j--;
		}
		else {
			if(dp[i-1][j] > dp[i][j-1]) i--;
			else j--;
		}
	}
	reverse(res.begin(), res.end());
	return res;
} 

// Longest Palindromic subsequence
int LPS(string a, int i, int j) {
	if(i>j) return 0;
	if(i==j) return 1;
	if(dp[i][j] != -1) return dp[i][j];
	if(a[i] == a[j]) return 2 + LPS(a,i+1,j-1);
	else return max(LPS(a, i+1, j), LPS(a, i, j-1));
}

int LIS(int a[], int n) {
	int dp[n] = {1};
	for(int i=1;i<n;i++) {
		int longest = 0;
		for(int j=0;j<i;j++) {
			if(a[j] < a[i]) { // Can only include if the element is smaller
				if(dp[j] > longest) longest = dp[j];
			}
		}
		dp[i] = longest+1; // adding this element upto LIS till now
	}

	int ans = 0;
	for(int i=0; i<n; i++) ans = max(dp[i],ans);
	return ans;
}

// Longest Bitonic Subsequence
int LBS(int a[], int n) {
	// first find LIS ending at i
	int lis[n] = {1};
	for(int i=1; i<n; i++) {
		int longest = 0;
		for(int j=0; j<i; j++) {
			if(a[j] < a[i] and longest < lis[j])
				longest = lis[j]; 
		}
		lis[i] = longest+1;
	}

	// find LDS starting at i, for this find LIS starting from backward ending at i
	int lds[n] = {1};
	for(int i=n-2; i>=0; i--) {
		int longest = 0;
		for(int j=n-1; j>i; j--) {
			if(a[j] < a[i] and longest < lds[j])
				longest = lds[j];
		}
		lds[i] = longest+1;
	}

	int ans = lis[0] + lds[0] - 1; // minus one because i is included in both
	for(int i=0; i<n; i++) ans = max(ans, lis[i] + lds[i] - 1);

	return ans;
}

/* InterviewBit atka hua problem
int fun(vector<int> d, vector<int> p, int bhookh, int n) {
    if(n == 0) return 0;
    if(bhookh == 0) return INT_MAX;
    if(dp[bhookh][n] != -1) return dp[bhookh][n];
    if(bhookh >= d[n-1]) 
        return dp[bhookh][n] = max(fun(d, p, bhookh - d[n-1], n) + p[n-1],
                    fun(d, p, bhookh, n-1));
    else return dp[bhookh][n] = fun(d, p, bhookh, n-1);
}*/

int knapsackZeroOne(int w[], int p[], int W, int n) {
	if(n==0 || W==0) return 0;
	if(dp[W][n] != -1) return dp[W][n];
	if(W >= w[n-1]) 
		return dp[W][n] = max(p[n-1] + knapsackZeroOne(w, p, W - w[n-1], n-1),
			knapsackZeroOne(w,p,W,n-1));
	return dp[W][n] = knapsackZeroOne(w, p, W, n-1);
}

int knapsackUnbounded(int w[], int p[], int W, int n) {
	if(n==0 || W==0) return 0;
	if(dp[W][n] != -1) return dp[W][n];
	if(W >= w[n-1]) 
		return dp[W][n] = max(p[n-1] + knapsackUnbounded(w, p, W - w[n-1], n),
			knapsackUnbounded(w,p,W,n-1));
	return dp[W][n] = knapsackUnbounded(w, p, W, n-1);
}

bool subsetSum(int a[], int sum, int n) {
	if(sum == 0) return true;
	if(sum != 0 and n == 0) return false;
	if(dp[sum][n] != -1) return dp[sum][n];
	if(sum >= a[n-1])
		return dp[sum][n] = (int)subsetSum(a, sum, n-1) or (int)subsetSum(a, sum-a[n-1], n-1);
	else return dp[sum][n] = (int)subsetSum(a, sum, n-1);
}

bool equalSumPartition(int a[], int n) {
	long long int sum = 0;
	for(int i=0;i<n;i++)
		sum += a[i];
	if((sum&1) == 0) return subsetSum(a, sum/2, n);
	else return false;
}

int countSubsetSum(int a[], int sum, int n) {
	if(sum == 0) return 1;
	if(sum != 0 and n == 0) return 0;
	if(dp[sum][n] != -1) return dp[sum][n];
	if(sum >= a[n-1])
		return dp[sum][n] = countSubsetSum(a, sum, n-1) + countSubsetSum(a, sum-a[n-1], n-1);
	else return dp[sum][n] = countSubsetSum(a, sum, n-1);
}

int mincoinChange(int a[], int target, int n, int count) {
	if(target == 0) return count;
	if(n==0) return INT_MAX;
	if(dp[target][n] != -1) return dp[target][n];
	if(target >= a[n-1]) 
		return dp[target][n] = min(mincoinChange(a, target - a[n-1], n, count+1),
					mincoinChange(a, target, n-1, count));
	return dp[target][n] = mincoinChange(a, target, n-1, count);
}

int matrixChainMultiplication(int a[], int i, int j) {
	if(i >= j) return dp[i][j] = 0;

	int ans = INT_MAX;
	for(int k=i; k<j; k++) {
		int cost = matrixChainMultiplication(a, i, k) + matrixChainMultiplication(a, k+1, j)
			 + a[i-1]*a[k]*a[j];
		ans = min(ans, cost);
	}
	return dp[i][j] = ans;
}

bool isPalindrome(string A) {    
    int left = 0;
    int right = A.size()-1;
    while(left < right) {
        if(A[left] != A[right]) {
            return 0;
        }
        left++;
        right--;
    }
    return 1;
}

int palindromePartition(string s, int i, int j) {
	if(i >= j) return 0;
	if(dp[i][j] != -1) return dp[i][j];
	if(isPalindrome(s.substr(i, j))) return 0;

	int ans = INT_MAX;
	for(int k=i; k<j; k++)
		ans = min(ans, palindromePartition(s, i, k) + 1 + palindromePartition(s, k+1, j));

	return dp[i][j] = ans;
}

// Only recursive approach, can easily memoize with 3d matrix
int booleanExpressionTrue(string s, int i, int j, bool isTrue) {
	if(i>j) return 0;
	if(i==j) {
		if(isTrue) return s[i] == 'T';
		else return s[i] == 'F';
	}
	int ans=0;
	for(int k=i+1; k<j; k+=2) {
		int lt = booleanExpressionTrue(s, i, k-1, true);
		int rt = booleanExpressionTrue(s, k+1, j, true);
		int lf = booleanExpressionTrue(s, i, k-1, false);
		int rf = booleanExpressionTrue(s, k+1, j, false);

		if(s[k] == '&') {
			if(isTrue) ans += lt*rt;
			else ans += lf*rf + lf*rt + lt*rf;
		}
		else if(s[k] == '|') {
			if(isTrue) ans += lt*rt + lf*rt + lt*rf;
			else ans += lf*rf;
		} 
		else if(s[k] == '^') {
			if(isTrue) ans += lf*rt + lt*rf;
			else ans += lf*rf + lt*rt;
		}
	}
	return ans;
}

// if(a.length()==b.length() and scrambledString(a,b)) cout << "True";
int scrambledString(string a, string b) {
	if(a == b) return true;
	if(a.length() <= 1) return false;
	int n = a.length();

	for(int i=1; i<n; i++) {
		// No swapping
		if(scrambledString(a.substr(0,i),b.substr(0,i)) and scrambledString(a.substr(i),b.substr(i)))
			return true;
		if(scrambledString(a.substr(0,i),b.substr(n-i)) and scrambledString(a.substr(i),b.substr(0,n-i)))
			return true;
	}
	return false;
}

int eggDrop(int e, int f) {
	if(f == 0 or f == 1) return f;
	if(e == 1) return f;
	if(dp[e][f] != -1) return dp[e][f];
	int ans = INT_MAX;
	for(int i=1; i<=f; i++) {
		int t = max(eggDrop(e-1,i-1), eggDrop(e, f-i));
		ans = min(ans, t);
	}
	return dp[e][f] = ans+1;
}

// Initialization is just making a string length j into empty string which takes j deletions
// Thereon it is just finding min + 1, or if chars are same then a[i-1][j-1] because replacing wont take any cost
int editDistance(string a, string b) {
	int n = a.length();
	int m = b.length();
	int t[n+1][m+1] = {0};

	for(int j=0; j<m; j++) t[0][j] = j;
	for(int i=0; i<n; i++) t[i][0] = i;

	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			if(a[i-1] == b[j-1]) t[i][j] = t[i-1][j-1];
			else t[i][j] = 1 + min(t[i-1][j], min(t[i-1][j-1], t[i][j-1]));
		}
	}
	return t[n][m];
}
/* GFG implementation, has good comments so will keep it
int editDist(string str1, string str2, int m, int n) 
{ 
    // If first string is empty, the only option is to 
    // insert all characters of second string into first 
    if (m == 0) 
        return n; 
  
    // If second string is empty, the only option is to 
    // remove all characters of first string 
    if (n == 0) 
        return m; 
  
    // If last characters of two strings are same, nothing 
    // much to do. Ignore last characters and get count for 
    // remaining strings. 
    if (str1[m - 1] == str2[n - 1]) 
        return editDist(str1, str2, m - 1, n - 1); 
  
    // If last characters are not same, consider all three 
    // operations on last character of first string, recursively 
    // compute minimum cost for all three operations and take 
    // minimum of three values. 
    return 1 + min(editDist(str1, str2, m, n - 1), // Insert (Gaurav Sen video has reason for this
    instead of using min(editDistance, str1, str2, m + 1, n))
                   editDist(str1, str2, m - 1, n), // Remove 
                   editDist(str1, str2, m - 1, n - 1) // Replace 
                   ); 
} */

/*Buy and sell stocks problem*/
// Buy and sell stocks problem III - at most k transactions
int buySellStocksK(int p[], int n, int k) {
	// dp[transaction][day]
	k = min(n,k);

	// Initialization step
	for(int i=0; i<=n; i++) dp[0][i] = 0; // Zero transactions
	for(int i=0; i<=k; i++) dp[i][0] = 0; // Cannot trade because cannot sell on first day


	for(int i=1; i<=k; i++) { // transactions
		int pdiff = INT_MIN;
		for(int j=1; j<n; j++) { // days
			pdiff = max(pdiff, dp[i-1][j-1] - p[j-1]);
			dp[i][j] = max(dp[i][j-1], p[j] + pdiff);
		}
	}
	return dp[k][n-1];
}


int main() {
	/*for(int i=0; i<10;i++) {
	}*/
	memset(dp, -1, sizeof dp);
	cout << a.size();
	return 0;
}