//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
//   int solve( vector<int>&dp,vector<int>& height,int ind){
//       if(ind == 0)return 0;
//       if(dp[ind]!= -1)return dp[ind];
      
//       int l = solve(dp,height,ind-1) + abs(height[ind] - height[ind-1]);
//       int r = INT_MAX;
//       if(ind>1)
//       r = solve(dp,height,ind-2) + abs(height[ind] - height[ind-2]);
//       return dp[ind] = min(l,r);
//   }
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector<int>dp(n+1,-1);
        dp[0] = 0;
        for(int i=1;i<n;i++){
            int ff = dp[i-1]+abs(height[i] - height[i-1]);
            int ss = INT_MAX;
            if(i>1)ss = dp[i-2]+ abs(height[i] - height[i-2]);
            dp[i] = min(ff,ss);
        }
        return dp[n-1];
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends