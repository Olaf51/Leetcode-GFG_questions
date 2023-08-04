//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    int solve(int i,string A,  vector<int> &dp, unordered_set<string> &st){
        if(i== A.size())
        return 1;
        if(dp[i]!= -1)return dp[i];
        for(int j=i;j<A.size();j++){
            if(st.count(A.substr(i,j-i+1)) && solve(j+1,A,dp,st))
            return dp[i] = 1;
        }
        return dp[i] = 0;
    }
    int wordBreak(string A, vector<string> &B) {
        //code here
        unordered_set<string> st(B.begin(), B.end());
        int m = A.size();
        vector<int> dp(m+1,-1);
        return solve(0,A,dp,st);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends