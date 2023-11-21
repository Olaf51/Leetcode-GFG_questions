class Solution {
public:
   int m = 1e9 + 7;
int rev(int n){
    int ans = 0;
    while(n>0){
        int rem  = n%10;
        ans = ans*10 +  rem;
        n /= 10;
    }
    return ans;
}
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++)
        nums[i] = nums[i] - rev(nums[i]);
        unordered_map<int,int>mp;
        int res = 0;
        for(int i=0;i<n;i++){
            res = (res + mp[nums[i]])%m;
            mp[nums[i]]++;
        }
        return res;
        
        
    }
};