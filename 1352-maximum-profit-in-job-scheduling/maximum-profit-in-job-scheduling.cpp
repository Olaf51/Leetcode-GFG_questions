class Solution {
public:
int memo[50001];
int n;
   int finalval(vector<vector<int>>&arr,int l, int endval){
       int r = n-1;
       int res = n+1;
       while(l<=r){
           int mid = l + (r-l)/2;
           if(arr[mid][0]>= endval){
               res = mid;
               r = mid-1;
           }
           else
           l = mid + 1;
       }
       return res;
   }
   int solve( vector<vector<int>>&arr, int i){
       if(i>=n)return 0;
       if(memo[i]!= -1)return memo[i];
       int nxtval = finalval(arr,i,arr[i][1]);
       int taken = arr[i][2] + solve(arr,nxtval);
       int nottaken = solve(arr,i+1);
       return memo[i] = max(taken, nottaken);
   }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        memset(memo, -1, sizeof(memo));
        n = startTime.size();
        vector<vector<int>>arr(n, vector<int>(3,0));
        for(int i=0;i<n;i++){
        arr[i][0] = startTime[i];
        arr[i][1] = endTime[i];
        arr[i][2] = profit[i];    
        }
        auto comp = [&](auto & vec1 , auto &vec2){
            return vec1[0] <vec2[0];
        };
        sort(begin(arr),end(arr), comp);
        return solve(arr,0);
    }
};