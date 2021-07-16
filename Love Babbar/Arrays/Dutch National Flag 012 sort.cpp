void sort012(int a[], int n)
    {
        int p0=0, p1=0, p2=n-1;
        while(p1<=p2) {
            switch(a[p1]) {
                case 0 :
                    swap(a[p1++], a[p0++]);
                    break;
                case 1 :
                    p1++;
                    break;
                case 2 :
                    swap(a[p1], a[p2--]);
                    break;
            }
        }
    }