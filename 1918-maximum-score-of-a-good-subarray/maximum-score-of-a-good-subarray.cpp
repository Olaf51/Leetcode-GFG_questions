// class Solution {
// public:
//     int maximumScore(vector<int>& nums, int k) {
//         int res = INT_MIN;
//         int i=k,j=k;
//         int n = nums.size();
//         int curmin = INT_MAX;
//         while(i>0 || j<n-1){
//             int leftval = (i>0)?nums[i-1]:0;
//             int rightval = (j<n-1)?nums[j+1]:0;
//             if(leftval > rightval){
//                 i--;
//               curmin = min(curmin, leftval);
//             }
//             else {
//                 j++;
//               curmin = min(curmin, rightval);
//             }
//             res = max(res, curmin*(j-i+1));
//         }
//         return res;
        
//     }
// };
class Solution {
public:
    int maximumScore(std::vector<int>& nums, int k) {
        int left = k, right = k;
        int min_val = nums[k];
        int max_score = min_val;

        while (left > 0 || right < nums.size() - 1) {
            if (left == 0 || (right < nums.size() - 1 && nums[right + 1] > nums[left - 1])) {
                right++;
            } else {
                left--;
            }
            min_val = std::min(min_val, std::min(nums[left], nums[right]));
            max_score = std::max(max_score, min_val * (right - left + 1));
        }
        
        return max_score;
    }
};