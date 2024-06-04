class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0,h=nums.size()-1;
        int mini = INT_MAX;
        while(l<=h){
            int m = l + (h-l)/2;
            if(nums[l]<= nums[m]){
                mini = min(mini,nums[l]);
                l = m+1;
            }
            else{
                mini = min(mini,nums[m]);
                h = m-1;
            }
        }
        return mini;
        
    }
};