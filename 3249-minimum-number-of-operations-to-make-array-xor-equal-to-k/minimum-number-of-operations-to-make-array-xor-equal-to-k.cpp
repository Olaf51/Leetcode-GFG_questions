class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int temp = nums[0];
        for(int i=1;i<nums.size();i++)
        temp = temp^nums[i];
        return __builtin_popcount(temp^k);
        
    }
};