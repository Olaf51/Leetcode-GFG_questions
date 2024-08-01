class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt=0;
        for(auto &x: details ){
            string age = "";
            age += x[11];
            age+= x[12];
            int a = stoi(age);
            if(a>60)cnt++;
        }
        return cnt;
        
    }
};