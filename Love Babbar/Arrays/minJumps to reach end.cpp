nt minJumps(int a[], int n){
        // Your code here
        int mreach = a[0], creach = a[0], steps=1;
        for(int i=0; i<n; i++) {
            if(i==n-1) return steps;
            mreach = max(mreach, a[i] + i);
            if(i==creach) {
                creach = mreach;
                steps++;
                if(i>=mreach) return -1;
            }
        }
        return -1;
    }