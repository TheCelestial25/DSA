int findLongestConseqSubseq(int arr[], int N)
{
  //Your code here
  set<int> s;
  int ans = 0;
  for(int i=0; i<N; i++) s.insert(arr[i]);
  for(int i=0; i<N; i++) {
      int e = arr[i];
      if(s.find(e-1) == s.end()) {
        int c = 0;
        while(s.find(e) != s.end()) {
            c++;
            e++;
        }
        ans = max(ans, c);   
      }
  }
  return ans;
}