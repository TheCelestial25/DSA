vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
{
    //code here.
    int i=0, j=0, k=0;
    vector<int> res;
    while(i<n1 and j<n2 and k<n3) {
        while(i<n1-1 and A[i]==A[i+1]) i++;
        while(j<n2-1 and B[j]==B[j+1]) j++;
        while(k<n3-1 and C[k]==C[k+1]) k++;
        if(A[i]==B[j] and B[j]==C[k]) {
            res.push_back(A[i]);
            i++;
            j++;
            k++;
        }
        while((A[i]<B[j] or A[i]<C[k]) and i<n1) i++;
        while((B[j]<C[k] or B[j]<A[i]) and j<n2) j++;
        while((C[k]<B[j] or C[k]<A[i]) and k<n3) k++;            
    }
    return res;
}