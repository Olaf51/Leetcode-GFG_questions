class Solution {
public:
    int minDeletions(string s) {
        vector<int>v(26,0);
        for(auto i: s)
        v[i-'a']++;

        int del = 0;
        sort(v.begin(),v.end());
        for(int i=24;i>=0;i--){
            if(v[i]==0)
            break;
            if(v[i]>=v[i+1]){
                int prev = v[i];
                v[i] = max(0,v[i+1]-1);
                del += prev-v[i];
            }
        }
        return del;
        
    }
};