class Solution {
public:
    int t[1001][1001];
    int mod = 1e9 + 7;
    int solve(int n, int k){
        if(n==0)return 0;
        if(k==0)return 1;
        if(t[n][k]!=-1)return t[n][k];
        int res = 0;
        for(int i=0;i<=min(k,n-1);i++)
        res = (res%mod + solve(n-1,k-i)%mod)%mod;

        return t[n][k] = res;

    }
    int kInversePairs(int n, int k) {
        memset(t,-1,sizeof(t));
        return solve(n,k);
        
    }
};