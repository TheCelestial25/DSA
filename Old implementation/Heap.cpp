#include <bits/stdc++.h>
using namespace std;

// HeapSort Implementation

void heapify(vector<int> &a, int n, int root) {
	if(root >= n) return;
	int largest = root;
	int left = 2*root + 1;
	int right = 2*root + 2;
	if(left < n and a[left] > a[largest])
		largest = left;
	if(right < n and a[right] > a[largest])
		largest = right;
	if(largest != root) {
		swap(a[largest], a[root]);
		heapify(a, n, largest);
	}
}
void heapSort(vector<int> &a, int n) {

	// build the initial heap from the tree
	for(int i=n/2-1; i>=0; i--) 
		heapify(a, n, i);

	while(--n) {
		swap(a[0], a[n]);
		heapify(a, n, 0);
	}
}

int main() {
	vector<int> a = {10,3,50,7,12,16};
	heapSort(a, 6);
	for(auto x : a) cout << x << " ";
	return 0;
}