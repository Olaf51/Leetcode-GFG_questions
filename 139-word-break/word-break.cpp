class Solution {
public:
bool solve(string s,  unordered_set<string>&st, vector<int>&memo, int i){
    if(i == s.size())return 1;
    if(memo[i]!= -1)return memo[i];
    for(int j=i;j<s.size();j++){
        if(st.count(s.substr(i,j+1-i)) && solve(s, st, memo,j+1)){
            memo[i] = true;
            return true;

        }
    }
    return memo[i] = false;
}
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st(wordDict.begin(), wordDict.end());
     
       int m = s.size();
        vector<int>memo(m+1,0);
       // return solve(s, st, memo,0);
        memo[0] = 1;
        for(int i=1;i<=m;i++){
           for(int j=0;j<i;j++){
               if(memo[j] && st.count(s.substr(j,i-j))){
                   memo[i] = 1;
                   break;
               }
           }
        }
        return memo[m];
        
    }
};