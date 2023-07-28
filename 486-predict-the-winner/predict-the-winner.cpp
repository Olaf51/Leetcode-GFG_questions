class Solution {
public:
   int find(vector<int>& nums,int i, int j,int flag, vector<vector<int>>&dp){
       if(i>j)
       return 0;
       if(dp[i][j]!=-1)return dp[i][j];
       if(flag == 0)
       return dp[i][j] =  max(nums[i] + find(nums,i+1,j,1,dp), nums[j] + find(nums,i,j-1,1,dp));
       else 
       return dp[i][j] =  min(find(nums,i+1,j,0,dp), find(nums,i,j-1,0,dp));
   }

    bool PredictTheWinner(vector<int>& nums) {
        long long sum = 0;
        int n = nums.size();
        vector<vector<int>>dp(n, vector<int>(n,-1));
        for(auto i: nums)
        sum += i;
        long long p1 = (long long)find(nums,0,n-1,0,dp);
        sum -= p1;
        if(p1>=sum)return true;
        return false;
        
    }
};