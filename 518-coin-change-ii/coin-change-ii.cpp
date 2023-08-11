class Solution {
public:
// int solve(int i,  vector<int>& coins,  vector<vector<int>>& dp, int t ){
//     if(i==0){
//     return (t%coins[i]==0);
//     }
//     if(dp[i][t]!=-1)return dp[i][t];
//     int ntake = solve(i-1,coins,dp,t);
//     int take = 0;
//     if(coins[i]<=t)
//     take = (i, coins,dp, t-coins[i]);
//     return dp[i][t] =  ntake + take;
// }
//     int change(int amount, vector<int>& coins) {
//         int n = coins.size();
//         vector<vector<int>>dp(n, vector<int>(amount+1,-1));
//         return solve(n-1, coins, dp, amount);
        
//     }
//  int f(int i, int j, vector<vector<int>>& dp, vector<int>& coins){
//         if(i==0){
//             return (j%coins[i]==0);
//         }
//         if(dp[i][j]!=-1){
//             return dp[i][j];
//         }
//         int nt=f(i-1, j, dp, coins), tk=0;
//         if(j>=coins[i]){
//             tk=f(i, j-coins[i], dp, coins);
//         }
//         return dp[i][j]=tk+nt;
//     }
    int change(int amount, vector<int>& coins) {
    //     int n=coins.size();
    //    vector<int>prev(amount+1,0) ;
    //   //  return f(n-1, amount, dp, coins);
    //     for(int i=0;i<=amount;i++){
    //         if(i%coins[0]==0)
    //         prev[i] = 1;
    //     }
    //     for(int i=1;i<n;i++){
    //         vector<int>curr(amount+1,0);
    //         for(int j=0;j<=amount;j++){
    //             int ntake = prev[j];
    //             int take = 0;
    //             if(coins[i]<=j)take = curr[j-coins[i]];
    //             coins[j] = take + ntake;
    //         }
    //         prev = curr;
    //     }
    //     return prev[amount];

    // }
     int n=coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, 0));
        for(int i=0; i<=amount; i++){
            dp[0][i]=(i%coins[0]==0);
        }
        for(int i=1; i<n; i++){
            for(int j=0; j<=amount; j++){
                int nt=dp[i-1][j], tk=0;
                if(j>=coins[i]){
                    tk=dp[i][j-coins[i]];
                }
                dp[i][j]=tk+nt;
            }
        }
        return dp[n-1][amount];
    }
};