class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dp(n,1),hash(n);
        for(int i=0;i<n;i++){
            hash[i]  = i;
            for(int prev = 0;prev<i;prev++){
                if(nums[i]%nums[prev]==0 && dp[i]<dp[prev]+1){
                    dp[i] = dp[prev]+1;
                    hash[i] = prev;
                }
            }
        }
        int ans = -1;
        int ind = -1;
        for(int i=0;i<n;i++){
            if(dp[i]>ans){
                ans = dp[i];
                ind = i;
            }
        }
        vector<int> res;
        res.push_back(nums[ind]);
        while(hash[ind]!= ind){
            ind = hash[ind];
            res.push_back(nums[ind]);
        }
        reverse(res.begin(),res.end());
        return res;
        
    }
};