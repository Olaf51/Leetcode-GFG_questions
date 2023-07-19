//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  int lcs(string a, string b,int i, int j, vector<vector<int>>&dp){
      if(i<0 || j<0)return 0;
      if(dp[i][j]!= -1)return dp[i][j];
      
      if(a[i]==b[j])
     return dp[i][j] = 1 + lcs(a,b,i-1,j-1,dp);
      else
      return dp[i][j] = max(lcs(a,b,i-1,j,dp), lcs(a,b,i,j-1,dp));
      
  }
    int longestPalinSubseq(string A) {
        //code here
        string a1 = A;
        string b1 = A;
        reverse(b1.begin(),b1.end());
        int n = A.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return lcs(a1,b1,n-1,n-1,dp);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends