class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)
        return {0};
        unordered_map<int,vector<int>>mp;
        vector<int>ind(n);
        for(auto &it: edges){
            int u = it[0];
            int v = it[1];
            ind[u]++;
            ind[v]++;
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        vector<int>res;
        queue<int>q;
        for(int i=0;i<n;i++){
            if(ind[i] == 1)
            q.push(i);
        }
        while(n>2){
            int s = q.size();
            n-= s;
            while(s--){
                int u = q.front();
                q.pop();
                for(auto &v : mp[u]){
                    ind[v]--;
                    if(ind[v] == 1)
                    q.push(v);
                }
            }
        }
        while(!q.empty()){
            res.push_back(q.front());
            q.pop();
        }

        return res;

        
    }
};