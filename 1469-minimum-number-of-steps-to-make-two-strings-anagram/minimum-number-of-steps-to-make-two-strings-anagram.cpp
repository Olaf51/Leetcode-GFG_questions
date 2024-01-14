class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int>mp;
        int n = s.size();
        int m = t.size();
        if(n!=m)return -1;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
            mp[t[i]]--;
        }
        int cnt = 0;
        for(auto it: mp){
            if(it.second >=0)
            cnt += it.second;
        }
        return cnt;
        
    }
};