class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int i=0,j=0;
        int n = nums.size(),res=0;
        while(j<n){
            mp[nums[j]]++;
           while(i<j && mp[nums[j]]>k){
            mp[nums[i]]--;
            i++;
           }
           res = max(res,j-i+1);
           j++;
        }
        return res;
        
    }
};