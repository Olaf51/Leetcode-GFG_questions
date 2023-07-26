class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
       int i, element=-1, max=0;
        unordered_map<int, int> m;

        for(i=0 ; i<nums.size() ; i++)
        {
            if(nums[i]%2==0)
            {
                m[nums[i]]++;
            }
        }
        for(auto it:m)
        {
            if(it.second>max)
            {
                max = it.second;
                element = it.first;
            }
            else if(it.second==max && it.first<element)
            {
                element = it.first;
            }
        }
        return element;
    }
};