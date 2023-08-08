        class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0,e= n-1;
        int piv = 0;
        while(s<=e){
        int m = s + (e-s)/2;
        if(nums[m]>=nums[0])
        s = m+1;
        else
        piv = m, e = m-1;
        }
        s =0,e=n-1;
        int t = piv;
        while(s<=t){
            int m =s + (t-s)/2;
            if(nums[m] == target)
            return m;
            else if(target<nums[m])
            t = m-1;
            else
            s = m+1;
        }
        while(piv<=e){
            int m =piv + (e-piv)/2;
            if(nums[m] == target)
            return m;
            else if(target<nums[m])
            e = m-1;
            else
            piv = m+1;
        }
        return -1;
    }
};