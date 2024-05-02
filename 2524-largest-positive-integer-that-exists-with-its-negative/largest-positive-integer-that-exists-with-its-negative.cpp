class Solution {
public:
    int findMaxK(vector<int>& nums) {
       int l =0;
       int r = nums.size()-1;
     sort(begin(nums),end(nums));
       while(l<r && nums[l]!=-nums[r]){
        if(-nums[l]>nums[r])l++;
        else
        r--;
       }
       int ans = l<r?nums[r]:-1;
       return ans;
        
    }
};