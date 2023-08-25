class Solution {
public:
   bool solve(int i1, int i2, string s1, string s2, string s3, vector<vector<int>>&dp){
       if(i1==s1.size() && i2==s2.size())return 1;
       if(dp[i1][i2]!= -1)return dp[i1][i2];
         int ans = 0;
       if(i1<s1.size() && s1[i1] == s3[i1+i2])
       ans = ans |  solve(i1+1,i2,s1,s2,s3,dp);
         if(i2<s2.size() && s2[i2] == s3[i1+i2])
       ans = ans |  solve(i1,i2+1,s1,s2,s3,dp);
       return dp[i1][i2] = ans;

   }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size()) return false;
        vector<vector<int>>dp(s1.size()+1, vector<int>(s2.size()+1,-1));
        return solve(0,0,s1,s2,s3, dp);
        
    }
};