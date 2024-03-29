class Solution {
public:
int t[101];
  int solve(vector<int>& nums,int n, int i){
      if(i>= n)return 0;
      if(t[i]!= -1)return t[i];

      int steal = nums[i] + solve(nums,n,i+2);
      int skip = solve(nums,n,i+1);
      return t[i] = max(steal,skip);
  }
    int rob(vector<int>& nums) {
        int n = nums.size();
      //  memset(t,-1,sizeof(t));
       // return solve(nums,n,0);
       t[0] = 0,t[1] = nums[0];
       for(int i=2;i<=n;i++){
           int steal = nums[i-1] + t[i-2];
           int skip = t[i-1];
           t[i] = max(steal,skip);
       }
       return t[n];
        

        
        
    }
};