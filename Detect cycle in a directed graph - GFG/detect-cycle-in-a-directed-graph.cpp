//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    // bool dfs(int node,vector<int>&vis,vector<int>&path,vector<int> adj[]){
    //     vis[node] = 1;
    //     path[node] = 1;
    //     for(auto it: adj[node]){
    //         if(!vis[it]){
    //             if(dfs(it,vis,path,adj) == true)return true;
    //         }
    //         else if(path[it]!=0)return true;
    //     }
    //     path[node] = 0;
    //     return  false;
    // }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        // vector<int>vis(V,0);
        // vector<int>path(V,0);
        // for(int i=0;i<V;i++){
        //     if(dfs(i,vis,path,adj)==true)return true;
        // }
        // return false;
        vector<int>ind(V,0);
        for(int i=0;i<V;i++){
            for(auto it: adj[i])
            ind[it]++;
        }
        queue<int>qt;
        for(int i=0;i<V;i++){
            if(ind[i] == 0)qt.push(i);
        }
        int cnt = 0;
        while(!qt.empty()){
            int temp = qt.front();
            qt.pop();
            cnt++;
            for(auto it: adj[temp]){
                ind[it]--;
                if(ind[it] == 0)qt.push(it);
            }
        }
        if(cnt == V)return false;
         return true;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends