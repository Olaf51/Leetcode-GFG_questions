class Solution {
public:
    string convertToTitle(int c) {
        string s = "";
        while(c>0){
            c = c-1;
           char t = 'A' + c%26;
           s += t;
           c /= 26;
         }
         reverse(s.begin(),s.end());
         return s;
    }
};