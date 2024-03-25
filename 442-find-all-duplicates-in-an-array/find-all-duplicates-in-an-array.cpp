class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>v;
        // map<int,int>mp;
        // for(auto i: nums)
        // mp[i]++;

        // for(auto i: mp){
        //     if(i.second>1)
        //     v.push_back(i.first);
        // }
        // return v;
        for(int& i : nums){
            if(nums[abs(i) - 1]<0)v.push_back(abs(i));
            else
            nums[abs(i)-1] = -nums[abs(i)-1];
        }
        return v;
        
    }
};