class Solution {
public:
//   int solve(string& s1, string& s2, int i, int j,  vector<vector<int>>&dp){
//       if(dp[i][j]!= -1)return dp[i][j];
//       if(i==s1.size()){
//           int sum = 0;
//           for(int k=j;k<s2.size();k++)
//           sum += (int)s2[k];
//           return sum;
//       }
//        if(j==s2.size()){
//           int sum = 0;
//           for(int k=i;k<s1.size();k++)
//           sum += (int)s1[k];
//           return sum;
//       }
//       int t1 = 1e9;
//       t1 = min(s1[i] + solve(s1,s2,i+1,j,dp), s2[j]+solve(s1,s2,i,j+1,dp));
//       int t2 = 1e9;
//       if(s1[i]==s2[j])
//       t2 = solve(s1,s2,i+1,j+1,dp);
//       return dp[i][j] = min(t1,t2);
//   }
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(),m = s2.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1,0));
       //return solve(s1,s2,0,0,dp);
       for(int i=1;i<=n;i++)
       dp[i][0] = dp[i-1][0] + s1[i-1];
       for(int j=1;j<=m;j++)
       dp[0][j] = dp[0][j-1] + s2[j-1];
       for(int i=1;i<=n;i++){
           for(int j=1;j<=m;j++){
               if(s1[i-1]==s2[j-1])
               dp[i][j] = dp[i-1][j-1];
               else
               dp[i][j] = min(s1[i-1]+dp[i-1][j],s2[j-1] + dp[i][j-1]);
           }
       }
       return dp[n][m];
    }
     
};