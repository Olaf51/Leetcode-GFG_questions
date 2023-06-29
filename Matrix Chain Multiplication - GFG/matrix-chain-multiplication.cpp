//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int i, int j, int arr[],  vector<vector<int>>&dp){
        if(i==j)return 0;
        if(dp[i][j]!= -1)return dp[i][j];
        int mini = INT_MAX;
        for(int k=i;k<=j-1;k++){
            int steps = solve(i,k, arr,dp) + solve(k+1,j, arr,dp) + arr[i-1]*arr[k]*arr[j];
            mini = min(mini, steps);
        }
        return dp[i][j] = mini;
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        vector<vector<int>>dp(N, vector<int>(N,-1));
        for(int i=1;i<N;i++)
         dp[i][i] = 0;
        //return solve(1,N-1,arr,dp);
        
        for(int i= N-1;i>=1;i--){
            for(int j = i+1;j<=N-1;j++){
                int mini = INT_MAX;
                for(int k=i;k<=j-1;k++){
                    int steps = arr[i-1]*arr[k]*arr[j] + dp[i][k] + dp[k+1][j];
                    mini = min(mini, steps);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][N-1];
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends