class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>hash(256,-1);
        int l=0,r=0;
       int mx = 0,n=s.size();
       while(r<n){
        if(hash[s[r]]!=-1){
             l = max(hash[s[r]]+1,l);
            }
            mx = max(mx,r-l+1);
        
            hash[s[r]] = r;
            r+=1;
        
        }
        return mx;
       }      
  
};