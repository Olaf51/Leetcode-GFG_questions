class Solution {
public:
    string multiply(string num1, string num2) {
          if (num1 == "0" || num2 == "0") return "0";
        int s1 = num1.size();
        int s2 = num2.size();
        vector<int>v(s1+s2,0);
        for(int i=s1-1;i>=0;--i){
            for(int j=s2-1;j>=0;--j){
                int prod = (num1[i]-'0')*(num2[j]-'0');
                int curr = v[i+j+1] + prod;
                v[i+j+1] = curr%10;
                v[i+j] += curr/10;
            }
        }
        int i = 0;
        while(i<v.size() && v[i]==0)++i;
        string res= "";
        while(i<v.size())
        res.push_back(v[i++]+'0');
        return res;
    }
};