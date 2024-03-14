class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // unordered_map<int,int>mp;
        // mp.insert({0,1});
        // int cumsum = 0,res=0;
        // for(int i=0;i<nums.size();i++){
        //       cumsum += nums[i];
        //       if(mp.find(cumsum-goal)!= mp.end())
        //       res += mp[cumsum-goal];
        //       mp[cumsum]++;
        // }
        // return res;
        int csum = 0,i=0,j=0,res=0,zero=0;
        while(j<nums.size()){
            csum += nums[j];
            while(i<j && (nums[i] == 0 || csum > goal)){
                if(nums[i] == 0)
                zero++;
                else
                zero = 0;
                csum -= nums[i];
                i++;
            }
            if(csum == goal)
            res += 1 + zero;
            j++;
        }
        return res;
    }
};