//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    // code here
	    unordered_map<int,int>mp;
	    int cnt = 0;
	    int k = pat.size();
	    for(auto it: pat)
	    mp[it]++;
	    int sz = mp.size();
	    int i=0;
	    int j=0;
	    while(j<txt.size()){
	        if(mp.find(txt[j])!= mp.end()){
	            mp[txt[j]]--;
	            if(mp[txt[j]]==0)
	            sz--;
	        }
	        if(j-i+1<k)
	        j++;
	        else{
	            if(sz == 0)
	            cnt++;
	            if(mp.find(txt[i]) != mp.end()){
	                mp[txt[i]]++;
	                if(mp[txt[i]]==1)
	                  sz++;
	            }
	            i++;
	            j++;
	        }
	    }
	    return cnt;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends