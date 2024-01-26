class Solution {
public:
int p;
int q;

int mod = 1e9 + 7;
vector<vector<int>>direc{{1,0},{-1,0},{0,1},{0,-1}};
//   int solve(int start, int end, int moves){
//       if(start>=p || start<0 || end>=q || end <0)return 1;
//       if(moves<=0)return 0;
//       if(t[start][end][moves]!= -1)return t[start][end][moves];
//       int res = 0;
//       for(auto dic: direc){
//           int x = start + dic[0];
//           int y = end + dic[1];
//           res = (res + solve(x,y,moves-1))%mod;
//       }
//       return t[start][end][moves] = res;
//   }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        p = m;
        q = n;
        int t[50][50][51];
        memset(t,0,sizeof(t));
       // return solve(startRow,startColumn,maxMove);
      for(int k=1;k<=maxMove;k++){
          for(int i=0;i<m;i++){
              for(int j=0;j<n;j++){
                  for(auto &dic: direc){
                      int x = i + dic[0];
                      int y = j + dic[1];
                      if(x>=m || x<0 || y>=n || y<0)
                      t[i][j][k] = (t[i][j][k] + 1)%mod;
                      else
                        t[i][j][k] = (t[i][j][k] + t[x][y][k-1])%mod;
                  }
              }
          }
      }
      return t[startRow][startColumn][maxMove];
        
    }
};