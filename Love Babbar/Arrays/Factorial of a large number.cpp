vector<int> factorial(int N){
    // code here
    vector<int> res;
    res.push_back(1);
    for(int i=1; i<=N; i++) {
        int carry = 0;
        for(int j=0; j<res.size(); j++) {
            int prod = res[j]*i;
            prod += carry;
            res[j] = (prod)%10;
            carry = prod/10;
        }
        while(carry>0) {
            res.push_back(carry%10);
            carry /= 10;
        }
    }
    reverse(res.begin(), res.end());
    return res;
}