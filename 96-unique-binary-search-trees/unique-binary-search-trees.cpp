class Solution {
public:
//    int solve(int n, vector<int>& dp){
//        if(n<=1)
//        return 1;
//        if(dp[n]!=-1)return dp[n];
//        int ans = 0;
//        for(int i=1;i<=n;i++)
//          ans += solve(i-1,dp)*solve(n-i,dp);
//          return dp[n] = ans;
//    }
//     int numTrees(int n) {
//         vector<int>dp(n,-1);
//         return solve(n,dp);
        
         int totalTrees(int n, int dp[]){
        if(n <= 1) return 1;
        if(dp[n]) return dp[n];
        
        for(int i=1; i<=n; i++){
            dp[n] += totalTrees(i-1,dp) * totalTrees(n-i,dp);
        }

        return dp[n];
    }
public:
    int numTrees(int n) {
        int dp[20] = {0};
        return totalTrees(n,dp);
    }
    
};