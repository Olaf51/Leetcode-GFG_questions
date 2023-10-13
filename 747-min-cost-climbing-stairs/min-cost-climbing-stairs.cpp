class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int dp1=0,dp2=0,dp=0;
        for(int i=2;i<=n;i++){
            int t1 = dp1 + cost[i-2];
            int t2 = dp2 + cost[i-1];
            dp = min(t1,t2);
            dp1 = dp2;
            dp2 = dp;

        }
        return dp2;
        
    }
};