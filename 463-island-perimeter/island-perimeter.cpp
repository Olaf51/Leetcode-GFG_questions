class Solution {
public:
int n = 0;
int m=0;
int peri=0;
// void dfs(vector<vector<int>>&grid, int i, int j){
//     if(i<0 || i>=n || j<0 || j>=m || grid[i][j] == 0){
//     peri++;
//     return ;
//     }
//     if(grid[i][j] == -1)return ;
//     grid[i][j] = -1;
//     dfs(grid,i+1,j);
//     dfs(grid,i-1,j);
//     dfs(grid,i,j-1);
//     dfs(grid,i,j+1);
// }
vector<vector<int>>direc{{1,0},{-1,0},{0,-1},{0,1}};
 int bfs(vector<vector<int>>&grid, int i, int j){
    queue<pair<int,int>>que;
    que.push({i,j});
    grid[i][j] = -1;

    while(!que.empty()){
        auto it = que.front();
        que.pop();
        for(auto &d: direc){
            int i_ = it.first + d[0];
            int j_ = it.second + d[1];
             if(i_<0 || i_>=n || j_<0 || j_>=m || grid[i_][j_] == 0)
             peri++;
             else if(grid[i_][j_]==-1)continue;

             else{
                que.push({i_,j_});
                grid[i_][j_] = -1;
             }

        }
    }
    return peri;

 }
    int islandPerimeter(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                   return  bfs(grid,i,j);
                    //return peri;
                }
            }
        }
        return -1;
        
    }
};