class Solution {
public:
   static bool comp(vector<int>&a,vector<int>&b){
   return a[1] <b[1];
   }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

    sort(begin(intervals),end(intervals), comp);
    int cnt=0;
    vector<int> prev = intervals[0];
    for(auto &it: intervals){
        if(it[0]< prev[1])cnt++;
        else
        prev = it;
    }
    return cnt-1;
        
    }
};