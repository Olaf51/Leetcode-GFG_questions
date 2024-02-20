class Solution {
public:
  int dp[301];
  int n;
  unordered_set<string>st;
   bool solve(int idx, string & s){
       if(idx == n)return true;
       if(dp[idx]!=-1)return dp[idx];
       if(st.find(s)!= st.end())return true;
       for(int i=1;i<=n;i++){
           string temp = s.substr(idx,i);
           if(st.find(temp)!= st.end() && solve(idx+i,s))
           return dp[idx] = true;
       }
       return dp[idx] = false;
   }
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(dp,-1,sizeof(dp));
        n = s.size();
        for(auto it: wordDict)
        st.insert(it);
        return solve(0,s);

        
    }
};