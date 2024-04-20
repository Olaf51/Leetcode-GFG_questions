class Solution {
public:
    // void bfs(int row, int col,vector<vector<int>>&vis, vector<vector<char>>& grid){
    //     vis[row][col] = 1;
    //     queue<pair<int,int>>q;
    //     q.push({row,col});
    //      int n = grid.size();
    //     int m = grid[0].size();
    //     while(!q.empty()){
    //         int row = q.front().first;
    //         int col = q.front().second;
    //         q.pop();
    //         for(int dr = -1;dr<=1;dr++){
    //             for(int dc = -1;dc<=1;dc++){
    //                 int nr = row + dr;
    //                 int nc = col + dc;
    //                 if(nr>=0 && nr<n && nc>0 && nc<m && !vis[nr][nc] && grid[nr][nc]== '1'){
    //                     vis[nc][nr] = 1;
    //                     q.push({nr, nc});
    //                 }
    //             }
    //         } 
    //     }
    // }
    // int numIslands(vector<vector<char>>& grid) {
    //     int n = grid.size();
    //     int m = grid[0].size();
    //     vector<vector<int>>vis(n, vector<int>(m,0));
    //     int cnt = 0;
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<m;j++){
    //             if(!vis[i][j] && grid[i][j] == '1'){
    //                 cnt++;
    //                 bfs(i,j,vis,grid);
    //             }
    //         }
    //     }
    //     return cnt;

        void bfs(int row,int col,vector<vector<bool>> &visited,vector<vector<char>> grid,int delrow[],int delcol[])
    {
        int n = grid.size();
        int m = grid[0].size();

        visited[row][col]=1;
        queue<pair<int,int>> q;
        q.push({row,col});

        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i=0;i<4;i++)
            {
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !visited[nrow][ncol] && grid[nrow][ncol]=='1')
                {
                    q.push({nrow,ncol});
                    visited[nrow][ncol]=1;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),0));
        int delrow[4]={1, 0, -1, 0};
        int delcol[4]={0, -1, 0, 1};
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(!visited[i][j] && grid[i][j]=='1')
                {
                    bfs(i,j,visited,grid,delrow,delcol);
                    count++;
                }
            }
        }

        return count;

    }
};