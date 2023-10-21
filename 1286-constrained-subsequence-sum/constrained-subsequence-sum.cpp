class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>pq;
        vector<int>t(nums.begin(),nums.end());
        pq.push({nums[0],0});
        int res = t[0];
        for(int i=1;i<nums.size();i++){
            while(!pq.empty() && i-pq.top().second >k)pq.pop();
            t[i] = max(t[i],nums[i] + pq.top().first);
            pq.push({t[i],i});
            res = max(res, t[i]);
        }
        return res;
        
    }
};