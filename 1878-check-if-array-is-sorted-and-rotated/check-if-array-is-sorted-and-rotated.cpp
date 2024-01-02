class Solution {
public:
    bool check(vector<int>& nums) {
        int flag =0;
        for(int i=0;i<nums.size()-1;i++){
           if(nums[i]>nums[i+1])
           flag++;
        }
        if(nums[0]<nums[nums.size()-1])
        flag++;
        return flag<=1;
        
    }
};