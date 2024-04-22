class Solution {
public:
int n;
int m;
vector<vector<int>>res;
vector<vector<int>>dir{{1,0},{-1,0},{0,1},{0,-1}};
  void dfs(vector<vector<int>>&land, int i, int j, int &r2, int &c2){
    land[i][j] = 0;
    r2 = max(r2,i);
    c2 = max(c2,j);
    for(auto &d: dir){
        int x = i + d[0];
        int y = j + d[1];
        if(x>=0 && x<n && y>=0 && y<m && land[x][y] == 1)
        dfs(land,x,y,r2,c2);
    }
  }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        n = land.size();
        m = land[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(land[i][j] == 1){
                    int r1=i,c1=j;
                    int r2=-1,c2=-1;
                    dfs(land,i,j,r2,c2);
                    res.push_back({r1,c1,r2,c2});
                }
            }
        }
        return res;
        
    }
};