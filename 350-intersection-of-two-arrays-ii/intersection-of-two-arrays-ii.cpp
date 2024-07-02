class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        sort(begin(nums1),end(nums1));
        sort(begin(nums2),end(nums2));
        int i=0,j=0;
        int n = nums1.size(),m=nums2.size();
        while(i<n && j<m){
            if(nums1[i]>nums2[j])
            j++;
            else if(nums2[j]>nums1[i])
            i++;
            else{
                ans.push_back(nums1[i]);
                i++;
                j++;
            }
        }
        return ans;
        
    }
};