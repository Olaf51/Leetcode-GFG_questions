class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long prod = 1;
        int n = nums.size();

        int cnt = 0,fz=-1;
         for(int i=0;i<n;i++){
            if(nums[i] == 0)
            cnt++;
            if(nums[i]!=0)
            prod = prod*nums[i];
        }
        if(cnt > 1){
         vector<int>ans(n,0);
         return ans;
         }
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                fz = i;
                break;
            }
        }
        if(cnt == 1){
             for(int i=0;i<n;i++){
                    if(i==fz)
                     nums[fz] = prod;
                     else
                     nums[i] = 0;
                         }
            return nums;
        }
        for(int i=0;i<n;i++){
            nums[i] = prod/nums[i];
        }
        return nums;


       
        
    }
};