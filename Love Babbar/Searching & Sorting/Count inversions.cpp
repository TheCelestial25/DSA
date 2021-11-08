long long int mergeSort(long long a[], long long temp[], int left, int right) {
    long long count = 0;
    if(left < right) {
        int mid = left + (right-left)/2;
        count += mergeSort(a, temp, left, mid);
        count += mergeSort(a, temp, mid+1, right);
        
        count += merge(a, temp, left, mid, right);
    }
    return count;
}

long long int merge(long long a[], long long temp[], int left, int mid, int right) {
    int i=left, j=mid+1, k=left;
    long long count = 0;
    while(i<=mid and j<=right) {
        if(a[i]<=a[j]) temp[k++] = a[i++];
        else {
            temp[k++] = a[j++];
            count += mid - i + 1;
        }
    }
    while(i<=mid) temp[k++] = a[i++];
    while(j<=right) temp[k++] = a[j++];
    
    for(int i=left; i<=right; i++) a[i] = temp[i];
    return count;
}
// arr[]: Input Array
// N : Size of the Array arr[]
// Function to count inversions in the array.
long long int inversionCount(long long arr[], long long N)
{
    // Your Code Here
    long long temp[N];
    return mergeSort(arr, temp, 0, N-1);
}