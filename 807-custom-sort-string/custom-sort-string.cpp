class Solution {
public:
    string customSortString(string order, string s) {
        // int cnt[26] = {0};
        // for(auto &ch : s)
        // cnt[ch-'a']++;

        // string res = "";
        // for(auto &it: order){
        //     while(cnt[it-'a']--)
        //     res.push_back(it);
        // }

        // for(auto &ch : s){
        //     if(cnt[ch-'a']>0){
        //        res.push_back(ch);
        //     }
        // }
        // return res;
        vector<int>cnt(26,0);
        for(int i=0;i<order.size();i++){
            char ch = order[i];
            cnt[ch-'a'] = i;
        }
        auto myComp = [&cnt](char &ch1, char &ch2){
            return cnt[ch1-'a'] < cnt[ch2-'a'];
        };
        sort(begin(s),end(s),myComp);
        return s;
    }
};