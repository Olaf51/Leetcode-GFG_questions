class Solution {
public:
int dp[501][501];
   int solve(int i, vector<int>&cost,int keemat, vector<int>& time){
       if(keemat <=0)return 0;
       if(i == cost.size())return 1e9;
       if(dp[i][keemat]!= -1)return dp[i][keemat];
       int npick = solve(i+1,cost,keemat,time);
       int pick = cost[i] + solve(i+1,cost,keemat-1-time[i],time);
       return dp[i][keemat] = min(pick, npick);
   }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        memset(dp,-1,sizeof(dp));
        return solve(0,cost,cost.size(),time);        
    }
};