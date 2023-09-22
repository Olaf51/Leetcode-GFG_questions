//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    vector<int> find(int arr[], int n , int x )
    {
        // code here
        int last = -1,first = -1,l=0,r= n-1;
        while(l<=r){
            int m = (l+r)>>1;
            if(arr[m]==x)
            last = m;
            if(arr[m]<= x)
            l = m + 1;
            else
            r = m-1;
        }
        l = 0;
        r = n-1;
         while(l<=r){
            int m = (l+r)>>1;
            if(arr[m]==x)
            first = m;
            if(arr[m] >= x)
            r = m - 1;
            else
            l = m + 1;
        }
        return {first, last};
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends