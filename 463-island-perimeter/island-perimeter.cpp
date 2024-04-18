class Solution {
public:
int n = 0;
int m=0;
int peri=0;
void dfs(vector<vector<int>>&grid, int i, int j){
    if(i<0 || i>=n || j<0 || j>=m || grid[i][j] == 0){
    peri++;
    return ;
    }
    if(grid[i][j] == -1)return ;
    grid[i][j] = -1;
    dfs(grid,i+1,j);
    dfs(grid,i-1,j);
    dfs(grid,i,j-1);
    dfs(grid,i,j+1);
}
    int islandPerimeter(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    dfs(grid,i,j);
                    return peri;
                }
            }
        }
        return -1;
        
    }
};