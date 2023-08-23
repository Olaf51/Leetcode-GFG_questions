//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
bool valid(int i,int j,int n ,int m)
{
    if(i>=0 && j>=0 && i<n && j<m)
    {
        return true;
    }
    return false;
}
 
bool solve(vector<vector<char>>&grid, string& word,int n,int m,int i,int j,int d1,int d2)
{
    int l=word.length();
    int flag =0;
    for(int t=0;t<l;t++)
    {
        if(valid(i,j,n,m))
        {
            if(word[t]!=grid[i][j])
            {
                return false;
            }
            
        }
        else
        {
            return false;
        }
        i= i+d1;
        j=j+d2;
    }
    return true;
    
}
vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
    // Code here
    
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>>res;
    
    int r[]={0,0,1,-1,-1,1,-1,1};
    int c[]={1,-1,0,0,1,1,-1,-1};
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            for(int k=0;k<8;k++)
            {
                int ans = solve(grid,word,n,m,i,j,r[k],c[k]);
           
                if(ans)
                {
                    vector<int>temp;
                    temp.push_back(i);
                    temp.push_back(j);
                    res.push_back(temp);
                    break;
                }
            }
            
        }
    }
    return res;
}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends