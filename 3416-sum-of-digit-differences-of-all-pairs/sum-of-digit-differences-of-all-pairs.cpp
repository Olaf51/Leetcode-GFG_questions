class Solution {
    #define ll long long int
public:
    unordered_map<int, unordered_map<int,int>>mp;
    void count(int num){
        string st = to_string(num);
        for(int i=0;i<st.size();i++){
            mp[i][st[i]]++;
        }
    }
    long long sumDigitDifferences(vector<int>& nums) {
        int n = nums.size();
        for(auto &temp : nums)count(temp);

        ll ans=0;
        for(auto &t: nums){
            string st = to_string(t);
            for(int i=0;i<st.size();i++)
            ans += (n*1ll - mp[i][st[i]]);
        }
        return ans/2;

        
    }
};