class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1 = -1,num2=-2, ct1=0, ct2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == num1)ct1++;
            else if(nums[i] == num2)ct2++;
            else if(ct1==0){
                num1 = nums[i];
                ct1 = 1;
            }
            else if(ct2 == 0){
                num2 = nums[i];
                ct2 = 1;
            }
            else{
                ct1--;
                ct2--;
            }
        }
        vector<int>v;
        ct1 = 0;
        ct2 = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == num1)ct1++;
            if(nums[i] == num2)ct2++;
        }
        if(ct1>nums.size()/3) v.push_back(num1);
        if(ct2>nums.size()/3) v.push_back(num2);

        return v;
        
    }
};

