class Solution {
public:
    int missingNumber(vector<int>& nums) {
      int mis =0;
      for(int i=0;i<nums.size();i++){
          mis ^= (i+1)^nums[i];
      }
      return mis;
        
    }
};