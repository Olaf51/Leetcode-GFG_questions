//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int nums[], int n, int x) {
	    // code here
	      int s = 0,e = n-1;
        int f=-1,l=-1;
        while(s<=e){
            int mid = s + (e-s)/2;
            if(x == nums[mid]){
                f = mid;
                e = mid-1;
            }
            else if(x< nums[mid])
            e = mid-1;
            else
            s = mid+1;
        }
        s = 0, e = n-1;
         while(s<=e){
            int mid = s + (e-s)/2;
            if(x == nums[mid]){
                l = mid;
                s = mid+1;
            }
            else if(x< nums[mid])
            e = mid-1;
            else
            s = mid+1;
        }
        if(f!=-1 && l!= -1)
        return l-f + 1;
        return 0;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends