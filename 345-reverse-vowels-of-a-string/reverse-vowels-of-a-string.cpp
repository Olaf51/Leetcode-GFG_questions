class Solution {
public:
    string reverseVowels(string s) {
         string v = "AEIOUaeiou";
         int st = 0;
         int e = s.size()-1;
         while(st<e){
                while(st<e && v.find(s[st]) == string::npos)
                    st++;
                while(e>st && v.find(s[e]) == string:: npos)e--;
                swap(s[st],s[e]);
                st++;
                e--;
                
         }
         return s;
    }
};