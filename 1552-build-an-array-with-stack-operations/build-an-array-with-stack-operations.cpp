class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int st = 1;
        int i=0;
        vector<string>res;
        while(i<target.size() && st <= n){
            res.push_back("Push");
            if(st == target[i])i++;
            else{
                res.push_back("Pop");
            }
            st++;
        }
        return res;        
    }
};