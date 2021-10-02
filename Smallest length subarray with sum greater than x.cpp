int sb(int arr[], int n, int x)
{
    // Your code goes here   
    int sum = 0, start = 0, end = 0, ans = n;
    while(end < n) {
        while(sum <= x and end < n) {
            sum += arr[end++];
        }
        while(sum > x and start < end) {
            sum -= arr[start++];
        }
        ans = min(ans, end - start + 1);
    }
    return ans;
}