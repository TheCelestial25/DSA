long long solve(vector<int> nums, int k, int i, int curr) {
    if(i==nums.size()) return 0;
    if(dp[i][curr] != -1) return dp[i][curr];
    int space = (curr == 0) ? 0 : 1;
    if(curr + space + nums[i] > k) {
        // Cannot keep here, remember that the next condition must be ahead of this one
        // because if not so, then we will just return 0 on the last value even if
        // not possible to place it here
        return dp[i][curr] = 1LL*(k-curr)*(k-curr) + solve(nums, k, i, 0);
    }
    if(i==nums.size()-1) {
        // if(curr == 0) return 0;
        return dp[i][curr] = 0;
    }
    long long ans = INT_MAX;
    if(curr != 0) {
        // Not keeping here, make sure to not leave the line empty
        ans = min(ans, 1LL*(k-curr)*(k-curr) + solve(nums, k, i, 0));
    }
    // Keeping it here
    ans = min(ans, solve(nums, k, i+1, curr + space + nums[i]));
    return dp[i][curr] = ans;
}
int solveWordWrap(vector<int>nums, int k) 
{ 
    // Code here
    memset(dp, -1, sizeof(dp));
    return solve(nums, k, 0, 0);
} 