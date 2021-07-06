// Program to find the minimum and maximum from an array with
// minimum comparisons (3n/2 - 2) vs 2(n-2) + 1 for standard way

#include <bits/stdc++.h>
using namespace std;

struct minimax {
    int min;
    int max;
};

minimax fun(int a[], int n) {
    minimax m;
    if(n==1) {
        m.min = a[0];
        m.max = a[0];
        return m;
    }
    int i;
    if(n%2==0) {
        if(a[0] > a[1]) {
            m.max = a[0];
            m.min = a[1];
        }
        else {
            m.max = a[1];
            m.min = a[0];
        }
        i = 2;
    }
    else {
        m.min = a[0];
        m.max = a[0];
        i = 1;
    }
    for(;i<n-1; i += 2) {
        if(a[i] > a[i+1]) {
            if(m.max < a[i])
                m.max = a[i];
            if(m.min > a[i+1])
                m.min = a[i+1];
        }
        else {
            if(m.max < a[i+1])
                m.max = a[i+1];
            if(m.min > a[i])
                m.min = a[i];
        }
    }
    return m;
}

int main() {
    int a[] = {1,2,3,4,45,0};
    minimax m = fun(a, 6);
    cout << m.min << " " << m.max;
    return 0;
}