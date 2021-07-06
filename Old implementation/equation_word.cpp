#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll t;
	cin >> t;
	while(t-- > 0) {
		double n,k;
		cin >> n >> k;
		double a = min(n,k);
		double b = max(n, k);
		cout << ceil(b/a) << endl;
	}
	return 0;
}