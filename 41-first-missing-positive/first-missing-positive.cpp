class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
    //    map<int,int>mp;
    //    for(auto i: nums)
    //    mp[i]++;
    //    for(int i=1;i<nums.size()+1;i++)
    //    {
    //        if(mp[i]==0)return i;
    //    }
    //    return nums.size()+1;
    // }
    int n = nums.size();
       for(int i=0;i<n;i++){
           if(nums[i]<=0)nums[i] = n + 1;
       }
       for(int i=0;i<n;i++){
           int ind = abs(nums[i])-1;
           if(ind<n && nums[ind]>0)nums[ind] *= -1;
       }
       for(int i=0;i<n;i++){
           if(nums[i]>0)return i+1;
       }
       return n+1;
    }
};