class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int>mp;
        mp.insert({0,1});
        int cumsum = 0,res=0;
        for(int i=0;i<nums.size();i++){
              cumsum += nums[i];
              if(mp.find(cumsum-goal)!= mp.end())
              res += mp[cumsum-goal];
              mp[cumsum]++;
        }
        return res;
    }
};