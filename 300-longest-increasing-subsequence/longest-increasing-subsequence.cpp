class Solution {
public:
 int solve(int i, int prev, int n,vector<vector<int>>&dp, vector<int>& nums){
     if(i==n)return 0;
     if(dp[i][prev+1] != -1)return dp[i][prev+1];
     int len = solve(i+1,prev,n, dp, nums);
     if(prev == -1 || nums[i]>nums[prev])
      len = max(len,1 + solve(i+1,i,n,dp,nums));
     return dp[i][prev+1] = len;
 }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1,0));
       // return solve(0, -1, n, dp, nums);
       for(int i=n-1;i>=0;i--){
           for(int p = i-1;p>=-1;p--){
                int ntake = dp[i+1][p+1];
                int take = 0;
                if(p == -1 || nums[i]>nums[p])
                take = 1 + dp[i+1][i+1];
               dp[i][p+1] = max(ntake, take);
            }

       }
       return dp[0][-1+1];
        
    }
};