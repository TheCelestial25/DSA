 int findDuplicate(vector<int>& a) {
    int slow = a[0];
    int fast = a[0];
    do {
        slow = a[slow];
        fast = a[a[fast]];
    } while(slow != fast);
    slow = a[0];
    while(slow != fast) {
        slow = a[slow];
        fast = a[fast];
    }
    return slow;
}


int findDuplicate(vector<int>& a) {
    for(int i=0; i<a.size(); i++) {
        if(a[abs(a[i])] < 0) return abs(a[i]);
        else a[abs(a[i])] *= -1;
    }
    return -1;
}