class Solution {
//    void solve(vector<int>& nums,  vector<vector<int>>ans, int n){
//        if(n >= nums.size()){
//            ans.push_back(nums);
//            return ;
//        }
//        for(int i = n;i<nums.size();i++){
//            swap(nums[n],nums[i]);
//            solve(nums,ans,n+1);
//            swap(nums[n],nums[i]);
//        }
       
       
//    } 
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        do{
            ans.emplace_back(nums);
        }while(next_permutation(nums.begin(),nums.end()));
        return ans;
    }
    // vector<vector<int>>ans;
    // int n = 0;
    // solve(nums,ans,n);
    // return ans;
};