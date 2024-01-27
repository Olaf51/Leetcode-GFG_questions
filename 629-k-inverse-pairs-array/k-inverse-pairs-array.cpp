class Solution {
public:
    int t[1001][1001];
    int mod = 1e9 + 7;
    // int solve(int n, int k){
    //     if(n==0)return 0;
    //     if(k==0)return 1;
    //     if(t[n][k]!=-1)return t[n][k];
    //     int res = 0;
    //     for(int i=0;i<=min(k,n-1);i++)
    //     res = (res%mod + solve(n-1,k-i)%mod)%mod;

    //     return t[n][k] = res;

    // }
    int kInversePairs(int n, int k) {
        memset(t,0,sizeof(t));
        for(int i=0;i<=n;i++)
        t[i][0] = 1;
        //return solve(n,k);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k;j++){
                for(int inv=0;inv<=min(j,i-1);inv++)
                t[i][j] = (t[i][j]%mod + t[i-1][j-inv]%mod)%mod;
            }
        }
        return t[n][k];
        
    }
};