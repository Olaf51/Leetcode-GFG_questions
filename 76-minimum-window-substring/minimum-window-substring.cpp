class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mp;
        for(auto &it: t)mp[it]++;
        int cnt=0,r=0,l=0,n=s.size(),mx = INT_MAX,start=-1;
        while(r<n){
           
            if(mp[s[r]]>0)cnt++;
             mp[s[r]]--;

            while(cnt == t.size()){
                int m = r-l+1;
                if(m<mx){
                    mx = m;
                    start = l;
                }
                mp[s[l]]++;
                if(mp[s[l]]>0)cnt--;
                l++;

            }
            r++;
        }
        return mx == INT_MAX ? "": s.substr(start,mx);

        
    }
};