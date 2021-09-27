int majorityElement(int a[], int size)
{
   // Boyer Moore voting algo go!
   int c = 1, e = a[0];
   for(int i=0; i<size; i++) {
       if(a[i] == e) c++;
       else c--;
       if(c == 0) {
           e = a[i];
           c = 1;
       }
   }
   // e could be our majority element
   // lets check now
   c = 0;
   for(int i=0; i<size; i++) if(a[i]==e) c++;
   if(c > size/2) return e;
   else return -1;
}