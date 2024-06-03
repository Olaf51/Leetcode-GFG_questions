class Solution {
public:
    int solve(vector<int>& nums, int k){
        unordered_map<int,int>mp;
        int cnt=0;
        int r=0,l=0,n=nums.size();
        while(r<n){
            mp[nums[r]]++;
           
                while(l<=r && mp.size()>k){
                    mp[nums[l]]--;
                    if(mp[nums[l]]==0)mp.erase(nums[l]);
                    l++;
                }
            
            cnt += r-l+1;
            r++;
        }
        return  cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);
        
    }
};