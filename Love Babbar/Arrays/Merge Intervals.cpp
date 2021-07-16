vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), mycomp);
    vector<vector<int>> v;
    vector<int> curr = intervals[0];
    for(int i=1; i<intervals.size(); i++) {
        if(intervals[i][0] > curr[1]) {
            // No overlap
            v.push_back(curr);
            curr = intervals[i];
        }
        else {
            curr[1] = max(curr[1], intervals[i][1]);
        }
    }
    v.push_back(curr);
    return v;
}