class Solution {
public:
   void solve(vector<int>&ucs,int temp, int &res, int ind){
       res = max(res, __builtin_popcount(temp));
       for(int i=ind;i<ucs.size();i++){
           if((temp & ucs[i]) == 0)
           solve(ucs,temp|ucs[i],res,i+1);
       }
   }
    int maxLength(vector<string>& arr) {
        vector<int>ucs;
        for(auto &s : arr){
            unordered_set<char>st(begin(s),end(s));
            if(st.size()!= s.size())continue;
            int val = 0;
            for(auto &it: s){
                val = ( val | (1<<(it-'a')));
            }
            ucs.push_back(val);
        }
        int temp = 0,res = 0;
        solve(ucs,temp,res,0);
        return res;
        
    }
};