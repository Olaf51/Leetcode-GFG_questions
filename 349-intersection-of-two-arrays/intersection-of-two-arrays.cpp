class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        for(auto it : nums1)
        mp[it]++;
        unordered_set<int>ans;
        for(auto &it: nums2){
            if(mp[it]>0)
            ans.insert(it);
        }
        vector<int>res(ans.begin(),ans.end());
        return res;
    }
};