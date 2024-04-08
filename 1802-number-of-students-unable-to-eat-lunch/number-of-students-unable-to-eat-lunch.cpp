class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        vector<int>cnt(2,0);
        for(auto i: students){
            cnt[i]++;
        }
        int n = sandwiches.size();
        for(auto i: sandwiches){
            if(cnt[i]==0)break;
            if(n==0)break;
            n--;
            cnt[i]--;
        }
        return n;

        
    }
};