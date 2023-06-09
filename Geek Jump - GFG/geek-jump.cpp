//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int solve( vector<int>&dp,vector<int>& height,int ind){
      if(ind == 0)return 0;
      if(dp[ind]!= -1)return dp[ind];
      
      int l = solve(dp,height,ind-1) + abs(height[ind] - height[ind-1]);
      int r = INT_MAX;
      if(ind>1)
      r = solve(dp,height,ind-2) + abs(height[ind] - height[ind-2]);
      return dp[ind] = min(l,r);
  }
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector<int>dp(n+1,-1);
        int ind = n-1;
        return solve(dp, height,ind);
        
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