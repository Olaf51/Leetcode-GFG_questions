class Solution {
public:
    bool isPalindrome(string s) {
        int st = 0;
        int e = s.size()-1;
        while(st<=e){
            if(!isalnum(s[st]))st++;
           else if(!isalnum(s[e]))e--;
           else{
            char x = tolower(s[st]);
            char y = tolower(s[e]);
            if(x!= y)return false;
            st++;
            e--;
           }
        }
        return true;
        
    }
};