class Solution {
public:
int dp[2001][4005];
int solve(vector<int>&v,int i, int ans){
    if(i>= v.size())return 0;
    if(dp[i][ans]!=-1)return dp[i][ans];
    int pick = 0;
    if(v[i]>ans)
    pick = v[i] + solve(v,i+1,ans + v[i]);

    int npick = solve(v,i+1,ans);
    return dp[i][ans] = max(pick,npick);

}
    int maxTotalReward(vector<int>& rewardValues) {
        memset(dp,-1,sizeof(dp));
        sort(begin(rewardValues), end(rewardValues));
        return solve(rewardValues,0,0);

        
    }
};