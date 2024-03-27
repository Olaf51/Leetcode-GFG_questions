class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i=0,j=0;
        long long prod=1;
        if(k<=1)return 0;
        int n = nums.size(),cnt=0;
        while(j<n){
            prod = prod*nums[j];
            while(prod >= k)prod = prod/nums[i++];
            cnt += 1 + (j-i);
            j++;
        }
        return cnt;
        
    }
};