//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
vector<int> complete(vector<int> &ans, int n){
      
        int index = ans.size()-1;
        if(n%2) index--;
            
        while(index >= 0)
        ans.push_back(ans[index--]);
        return ans;
    }
    vector<int> generateNextPalindrome(int num[], int n) {
        // code here
        vector<int> ans;
        
        int s=0, e=n-1;
        bool safe = 0, all9 = 1;;
        
        while(s <= e){
            ans.push_back(num[s]);
            
            if(num[s] != 9 || num[e] != 9) all9 = 0;
            
            if(num[s] > num[e]) safe = 1;
            else if(num[s] < num[e]) safe = 0;
            
            s++; e--;
        }
        
        if(all9){
            vector<int> num;
            num.push_back(1);
            for(int i=0; i<n-1; i++) num.push_back(0);
            num.push_back(1);
            return num;
        }
        
        if(safe) return complete(ans, n);
        
        int carry = 1;
        int len = ans.size();
        int ind2 = len-1;
        int update;
        
        while(carry){
            update = ans[ind2] + carry;
            ans[ind2--] = update%10;
            carry = update/10;
        }
        return complete(ans, n);
	}

};

//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int num[n];
        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }
        Solution ob;
        auto ans = ob.generateNextPalindrome(num, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends