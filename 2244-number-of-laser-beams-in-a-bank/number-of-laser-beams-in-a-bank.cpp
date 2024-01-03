class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int>vec;
        for(auto cnt: bank){
            int ct = 0;
            for(auto &i: cnt){
                if(i=='1')
                  ct++;
            }
            if(ct)
            vec.push_back(ct);

        }
        if(vec.size()<=1)return 0;
        int ans =0;
        for(int i=0;i<vec.size()-1;i++)
        ans += vec[i]*vec[i+1];

        return ans;
        
    }
};