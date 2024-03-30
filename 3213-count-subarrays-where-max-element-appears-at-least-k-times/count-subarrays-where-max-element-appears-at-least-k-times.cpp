class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n =nums.size(),i=0,j=0;
        int cnt=0,maxi=INT_MIN,mcnt=0;
        long long res=0;
        for(auto it: nums){
            maxi = max(maxi,it);
        }
        while(j<n){
            if(nums[j] == maxi){
                mcnt++;
            }
            while(mcnt>=k){
               res+= n-j;
               if(nums[i]==maxi)
               mcnt--;
               i++;
            }
            j++;
        }
        return res;
        

        
    }
};