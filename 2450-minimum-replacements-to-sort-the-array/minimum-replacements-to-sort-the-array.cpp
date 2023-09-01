class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size();
        long long val = nums[n-1];
        long long res = 0;
        for(int i=n-2;i>=0;i--){
            long long parts = ceil(nums[i]/(double)val);
            res += parts-1;
            val = nums[i]/parts;
        }
        return res;
                
    }
};