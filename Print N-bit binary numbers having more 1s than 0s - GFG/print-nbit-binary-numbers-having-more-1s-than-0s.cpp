//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
   void solve(int one, int zero, string op, int n, vector<string>&ans){
       if(n==0){
           ans.push_back(op);
           return ;
       }
       solve(one+1,zero,op+'1',n-1,ans);
       if(one>zero){
           solve(one,zero+1,op+'0',n-1,ans);
       }
       
   }
	vector<string> NBitBinary(int N)
	{
	    // Your code goes here
	    int one =0, zero=0;
	    vector<string>ans;
	    string op= "";
	    solve(one,zero,op,N,ans);
	    return ans;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends