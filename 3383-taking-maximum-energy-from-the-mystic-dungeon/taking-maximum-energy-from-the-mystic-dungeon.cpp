class Solution {
public:
//   int dp[100002];
//   int solve(vector<int>& energy, int k,int i){
//     if(i>=energy.size())return 0;
//      if(dp[i]!=-1)return dp[i];
//     return dp[i] = energy[i] + solve(energy,k,i+k);
//   }
    int maximumEnergy(vector<int>& energy, int k) {
        // memset(dp,-1,sizeof(dp));
        // int ans = INT_MIN;
        // for(int i=0;i<energy.size();i++)
        //       ans = max(ans,solve(energy,k,i));
        //       return ans;
        int ans = -1001;
        for(int i=energy.size()-1;i>=0;i--){
            energy[i]+= (i+k)<energy.size()?energy[i+k]:0;
            ans = max(energy[i], ans);
        }
        return ans;
        
    }
};