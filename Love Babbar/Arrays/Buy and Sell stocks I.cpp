int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int low = prices[0], profit = 0;
    for(int i=0; i<n; i++) {
        low = min(low, prices[i]);
        profit = max(profit, prices[i]-low);
    }
    return profit;
}