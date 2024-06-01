class Solution {
public:
    int scoreOfString(string s) {
        int n = s.size();
        int ans = 0;
        for(int i=0;i<n-1;i++){
            int t = s[i] - '0';
            int p = s[i+1]-'0';
            ans += abs(t-p);
        }
        return ans;
        
    }
};