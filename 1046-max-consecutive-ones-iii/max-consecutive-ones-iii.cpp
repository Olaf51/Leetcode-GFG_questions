class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0,r=0;
        int n = nums.size(),t=0, mx=0;
        while(r<n){
            
         if(!nums[r])k--;
            while(k<0){
                if(!nums[l])k++;
                l++;
            }
            mx = max(mx,r-l+1);
            r++;

        }
        return mx;
        
    }
};