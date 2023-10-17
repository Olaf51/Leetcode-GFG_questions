class Solution {
public:
 long long  dp[501][501];
 long long mod = 1e9 + 7;
    int solve(int i, int steps, int len){
        if(i<0 || i>=len)
        return 0;
        if(steps == 0){
            if(i == 0)return 1;
            return 0;
        }
        if(dp[i][steps]!=-1)return dp[i][steps];
        long long l = solve(i-1,steps-1,len)%mod;
        long long r = solve(i+1,steps-1,len)%mod;
        long long s = solve(i,steps-1,len)%mod;
        return dp[i][steps] = (l+r+s)%mod;

    }
    int numWays(int steps, int arrLen) {
       memset(dp,-1,sizeof(dp));
       return solve(0,steps,arrLen);
        
    }
};