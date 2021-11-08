bool zeroes(int num,int n){
    int five=5,count=0;
    while(five<=num){
        count+=num/five;
        five*=5;
    }
    return count>=n;
}
int findNum(int n)
{
    if(n==1) return 5;
    //Maximum number with n 
    //trailing zeroes is 5*n
    int m,l=0,r=5*n;
    //Binary Search for minimum number with 
    //n trailing zeroes
    while(l<r){
        m=(l+r)/2;
         if(zeroes(m,n))
           r=m;
         else
           l=m+1;
    }
    return l;
}