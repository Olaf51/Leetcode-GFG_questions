class Solution {
public:
  vector<vector<int>>res;
  vector<int>ans;
  void solve(int h, int n, int k){
      if(k==0){
          res.push_back(ans);
          return ;
      }
      if(h== n+1)return ;
      solve(h+1,n,k);
      ans.push_back(h);
      solve(h+1,n,k-1);
      ans.pop_back();
      
  }
    vector<vector<int>> combine(int n, int k) {
        solve(1,n,k);
        return res;
        
    }
};