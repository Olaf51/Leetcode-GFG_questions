class Solution {
public:
int m;
int n;
vector<vector<int>>dir{{1,0},{-1,0},{0,1},{0,-1}};
  bool solve(int i, int j, int idx, string &word,vector<vector<char>>& board){
      if(idx >= word.size())return true;
      if(i<0 || j<0 || j>=n || i>=m || board[i][j]=='$')return false;
      if(board[i][j]!=word[idx])return false;
      char temp = board[i][j];
      board[i][j] = '$';
      for(auto &d: dir){
          int i_ = i + d[0];
          int j_ = j + d[1];
          if(solve(i_,j_,idx+1,word,board))return true;
      }
      board[i][j] = temp;
      return false;

   
  }
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == word[0] && solve(i,j,0,word,board))
                return true;
            }
        }
        return false;
        
    }
};