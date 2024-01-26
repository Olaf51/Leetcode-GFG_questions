class Solution {
public:
int p;
int q;
int t[51][51][51];
int mod = 1e9 + 7;
vector<vector<int>>direc{{1,0},{-1,0},{0,1},{0,-1}};
  int solve(int start, int end, int moves){
      if(start>=p || start<0 || end>=q || end <0)return 1;
      if(moves<=0)return 0;
      if(t[start][end][moves]!= -1)return t[start][end][moves];
      int res = 0;
      for(auto dic: direc){
          int x = start + dic[0];
          int y = end + dic[1];
          res = (res + solve(x,y,moves-1))%mod;
      }
      return t[start][end][moves] = res;
  }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        p = m;
        q = n;
        memset(t,-1,sizeof(t));
        return solve(startRow,startColumn,maxMove);
        
    }
};