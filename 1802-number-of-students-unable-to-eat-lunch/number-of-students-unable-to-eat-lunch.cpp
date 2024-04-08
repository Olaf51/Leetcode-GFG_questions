class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        unordered_map<int,int>mp;
        for(auto i: students)mp[i]++;
        for(auto i: sandwiches){
            if(mp[i] == 0)break;
            mp[i]--;
        }
        return mp[0] + mp[1];

        
    }
};