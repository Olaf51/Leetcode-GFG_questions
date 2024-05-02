class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int>t(26,0);
        int res = 0;
        for(int i=0;i<s.size();i++){
            char ch = s[i]-'a';
            int left = max(0,ch-k);
            int right = min(25,ch+k);
            int longest = 0;
            for(int j=left;j<=right;j++){
                longest = max(longest,t[j]);
            }
            t[ch] = max(t[ch],longest+1);
            res = max(res, t[ch]);
        }
        return res;
        
    }
};