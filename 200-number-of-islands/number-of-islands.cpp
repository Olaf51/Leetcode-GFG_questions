class Solution {
public:
int m;
int n;
//   void dfs(vector<vector<char>>& grid,int i,int j){
//     if(i<0 || i>=n || j<0 || j>=m || grid[i][j]=='0' || grid[i][j] == '$')return ;
    
//     grid[i][j] = '$';
//     dfs(grid,i+1,j);
//     dfs(grid,i-1,j);
//     dfs(grid,i,j+1);
//     dfs(grid,i,j-1);
//   }
vector<vector<int>>dir{{1,0},{-1,0},{0,1},{0,-1}};
void bfs(vector<vector<char>>&grid, int i, int j){
    queue<pair<int,int>>q;
    q.push({i,j});
    while(!q.empty()){
        auto temp = q.front();
        q.pop();
        for(auto it: dir){
            int x = temp.first + it[0];
            int y = temp.second + it[1];
             if(x<0 || x>=n || y<0 || y>=m || grid[x][y]!='1')continue;
             else{
                q.push({x,y});
                grid[x][y] = '$';
             }

        }
    }
}
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int cnt =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    bfs(grid,i,j);
                    cnt++;
                }
            }
        }
        return cnt;
        
    }
};