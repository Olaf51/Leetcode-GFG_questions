class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0;
        int n = nums.size();
        int ans = INT_MIN;
        while(j<n){

       if(!nums[j]) k--;
       while(k<0){
           if(!nums[i])
           k++;
           i++;
       }
       ans = max(ans,j-i+1);
       j++;
        }
        return ans;
        
    }
};