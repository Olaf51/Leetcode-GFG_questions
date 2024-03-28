class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int i=0,j=0;
        int n = nums.size(),res=0,cul=0;
        while(j<n){
            mp[nums[j]]++;
            if(mp[nums[j]] == k+1)
            cul++;
            if(cul>0){
                mp[nums[i]]--;
                if(mp[nums[i]] == k)
                cul--;
                i++;
            }
        //    while(i<j && mp[nums[j]]>k){
        //     mp[nums[i]]--;
        //     i++;
        //    }
        if(cul == 0)
           res = max(res,j-i+1);
           j++;
        }
        return res;
        
    }
};