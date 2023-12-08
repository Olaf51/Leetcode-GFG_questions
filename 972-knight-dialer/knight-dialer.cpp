class Solution {
public:
int mod = 1e9 + 7;
vector<vector<int>>adj = {
    {4,6},
    {6,8},
    {7,9},
    {4,8},
    {3,0,9},
    {},
    {1,7,0},
    {2,6},
    {1,3},
    {2,4}};
    int dp[5000][10];
    int solve(int n, int cell){
        if(n==0)return 1;
        if(dp[n][cell]!= -1)return dp[n][cell];
        int ans = 0;
        for(auto c : adj[cell])
        ans = (ans + solve(n-1,c))%mod;
        return dp[n][cell] = ans;
    }

    int knightDialer(int n) {
        memset(dp, -1, sizeof(dp));
        int res = 0;
        for(int cell = 0;cell<=9;cell++){
            res  = (res + solve(n-1,cell))%mod;
        }
        return res;
    }
};