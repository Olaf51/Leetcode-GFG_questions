//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
// int solve(int *arr,int ind,vector<int>&dp ){
//     if(ind<0) return 0;
//     if(ind == 0)return arr[0];
//     if(dp[ind] != -1)return dp[ind];
//     int pick = arr[ind] + solve(arr,ind-2,dp);
//     int n_pick = solve(arr,ind-1,dp);
//     return dp[ind] = 0+ max(pick,n_pick);
//}
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    // code here
	   // vector<int>dp(n+1,-1);
	    //dp[0] = arr[0]; 
	    int prev = arr[0], prev2 = 0;
	   // return solve(arr, n-1,dp);
	   for(int i=1;i<n;i++){
	       int pick = arr[i];
	       if(i>1) pick += prev2;
	       int n_pick = 0+ prev;
	       int curr = max(pick,n_pick);
	       prev2 = prev;
	       prev = curr;
	   }
	   return prev;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends