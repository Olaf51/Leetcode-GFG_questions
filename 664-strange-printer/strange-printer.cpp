class Solution {
public:
    int solve(const string& s,int i,int j,vector<vector<int>>&dp){
        if(i==j)return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans = INT_MAX;
        for(int k=i;k<j;k++)
        ans = min(ans, solve(s,i,k,dp)+solve(s,k+1,j,dp));
        if(s[i]==s[j])
        return dp[i][j] = ans-1;
        else
        return dp[i][j] = ans;
    }
    int strangePrinter(string s) {
      int n = s.size();
      vector<vector<int>>dp(n,vector<int>(n,-1));
      return solve(s,0,n-1,dp); 
    }
};