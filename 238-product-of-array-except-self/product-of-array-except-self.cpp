class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // long long prod = 1;
        // int n = nums.size();

        // int cnt = 0,fz=-1;
        //  for(int i=0;i<n;i++){
        //     if(nums[i] == 0)
        //     cnt++;
        //     if(nums[i]!=0)
        //     prod = prod*nums[i];
        // }
        // if(cnt > 1){
        //  vector<int>ans(n,0);
        //  return ans;
        //  }
        // for(int i=0;i<n;i++){
        //     if(nums[i]==0){
        //         fz = i;
        //         break;
        //     }
        // }
        // if(cnt == 1){
        //      for(int i=0;i<n;i++){
        //             if(i==fz)
        //              nums[fz] = prod;
        //              else
        //              nums[i] = 0;
        //                  }
        //     return nums;
        // }
        // for(int i=0;i<n;i++){
        //     nums[i] = prod/nums[i];
        // }
        // return nums;
        int n = nums.size();
        vector<int>res(n);
        res[0] = 1;
        for(int i=1;i<n;i++)
        res[i] = nums[i-1]*res[i-1];

        int rprod=1;
        for(int i=n-1;i>=0;i--){
            res[i] = res[i]*rprod;
            rprod = rprod*nums[i];
        }
        return res;


       
        
    }
};