class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        if(t.size()>n)return "";
        unordered_map<char,int>mp;
        for(auto &ch: t)
        mp[ch]++;
        int i=0,j=0,start_i=0;
        int widSize = INT_MAX, curCnt = t.size();
        while(j<n){

            if(mp[s[j]]>0)
            curCnt --;
            mp[s[j]]--;
            while(curCnt == 0){
                int currSize = j-i+1;
                if(widSize > currSize){
                    widSize = currSize;
                    start_i = i;
                }
                mp[s[i]]++;
                if(mp[s[i]]>0)
                curCnt++;
                i++;

            }
            j++;
        }
        return widSize == INT_MAX ? "":  s.substr(start_i,widSize);
    }
};