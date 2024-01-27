class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int t[1001][1001];
        memset(t,-1,sizeof(t));
        int n = text1.size();
        int m =text2.size();
       // for(int i=0;i<text1.size();i++)t[i][0] = 0;
        //for(int i=0;i<text2.size();i++)t[0][i] = 0;
        vector<int>curr(m+1,0),prev(m+1,0);
        for(int i=1;i<=text1.size();i++){
            for(int j =1;j<=text2.size();j++){
                if(text1[i-1] == text2[j-1])
                curr[j] = 1 + prev[j-1];
                else
                curr[j] = max(prev[j] , curr[j-1]);
            }
            prev = curr;
        }
      //  return t[text1.size()][text2.size()];
      return prev[m];

        
    }
};