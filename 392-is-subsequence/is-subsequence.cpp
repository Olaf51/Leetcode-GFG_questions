class Solution {
public:
    bool isSubsequence(string s, string t) {
        int j=0, n = t.size();
        for(int i=0;i<n;i++){
            if(t[i] == s[j])
            j++;
            
        }
        if(j == s.size())
            return true;
        return false;
        
    }
};