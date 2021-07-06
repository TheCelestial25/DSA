#include <bits/stdc++.h>
#define ll long long
using namespace std;

int heap_size;

void maxHeapify(int arr[], int root, int n) {
	int mx = root; // max value node among parent and children
	int left = 2*root + 1;
	int right = 2*root + 2;
	if(right < n and arr[mx] < arr[right])
		mx = right;
	if(left < n and arr[mx] < arr[left])
		mx = left;
	if(root!=mx) { // Heap property is not satisfied
		swap(arr[root], arr[mx]);
		maxHeapify(arr, mx, n);
	}
}

void minHeapify(int arr[], int root, int n) {
	int mn = root; // max value node among parent and children
	int left = 2*root + 1;
	int right = 2*root + 2;
	if(right < n and arr[mn] > arr[right])
		mn = right;
	if(left < n and arr[mn] > arr[left])
		mn = left;
	if(root!=mn) { // Heap property is not satisfied
		swap(arr[root], arr[mn]);
		minHeapify(arr, mn, n);
	}
}

int getMax(int arr[]) {
	if(heap_size==0)
		return INT_MIN;
	int res = arr[0]; // Root is the largest
	arr[0] = arr[heap_size-1];
	heap_size--;
	maxHeapify(arr, 0, heap_size);
	return res;
}

int getMin(int arr[]) {
	if(heap_size==0)
		return INT_MIN;
	int res = arr[0]; // Root is the largest
	arr[0] = arr[heap_size-1];
	heap_size--;
	minHeapify(arr, 0, heap_size);
	return res;
}

void buildMaxHeap(int arr[], int n) {
	int st = n/2 - 1;
	// Parent of a node in binary tree = (n-1)/2, verify with 0,1 and 2 as node indexes
	// Parent of last node ie (n-1)th node = ((n-1)-1)/2 = n/2 - 1

	for(int i=st; i>=0; i--) {
		maxHeapify(arr, i, n);
	}
}

void buildMinHeap(int arr[], int n) {
	int st = n/2 - 1;
	// Parent of a node in binary tree = (n-1)/2, verify with 0,1 and 2 as node indexes
	// Parent of last node ie (n-1)th node = ((n-1)-1)/2 = n/2 - 1

	for(int i=st; i>=0; i--) {
		minHeapify(arr, i, n);
	}
}

int main() {
	int a[] = {7,10,4,3,20,15};
	int n = sizeof(a)/sizeof(a[0]);
	heap_size = n;
	buildMinHeap(a, n);
	// kth largest
	int k = 3;
	int res;
	while(k--) res = getMin(a);
	cout << res;
	return 0;
}