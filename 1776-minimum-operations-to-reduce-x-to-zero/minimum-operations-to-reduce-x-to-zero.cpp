class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0;
        for(auto i: nums)
        sum += i;
        sum -= x;
        if(sum<0)return -1;
        int l =0, cursum=0, ans = INT_MIN;
        for(int i=0;i<nums.size();i++){
            cursum += nums[i];
            while(cursum > sum){
                cursum -= nums[l];
                l++;
            }
            if(cursum==sum)
            ans = max(ans, i-l + 1);
        }
      return ans== INT_MIN ? -1: nums.size()-ans;
    }
};