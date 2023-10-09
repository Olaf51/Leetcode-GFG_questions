class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int f=-1,l=-1;
        int s = 0, e = nums.size()-1;
        while(s<=e){
            int mid = (e-s)/2 + s;
            if(nums[mid]==target){
                f = mid;
                e = mid-1;
            }
            else if(nums[mid]>target)
            e = mid-1;
            else
            s = mid+1;
        }
        s= 0;
        e = nums.size()-1;
         while(s<=e){
            int mid = (e-s)/2 + s;
            if(nums[mid]==target){
                l = mid;
                s = mid+1;
            }
            else if(nums[mid]>target)
            e = mid-1;
            else
            s = mid+1;
        }
        return {f,l};
        
    }
};