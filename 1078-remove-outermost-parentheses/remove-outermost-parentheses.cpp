class Solution {
public:
    string removeOuterParentheses(string s) {
        int temp=0;
        string res = "";
        for(auto c: s){
            if(c=='(' && temp++ >0)res+=c;
            if(c==')' && temp-->1)res+=c;
        }
        return res;
        
    }
};