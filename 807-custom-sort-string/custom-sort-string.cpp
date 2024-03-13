class Solution {
public:
    string customSortString(string order, string s) {
        int cnt[26] = {0};
        for(auto &ch : s)
        cnt[ch-'a']++;

        string res = "";
        for(auto &it: order){
            while(cnt[it-'a']--)
            res.push_back(it);
        }

        for(auto &ch : s){
            if(cnt[ch-'a']>0){
               res.push_back(ch);
            }
        }
        return res;
    }
};