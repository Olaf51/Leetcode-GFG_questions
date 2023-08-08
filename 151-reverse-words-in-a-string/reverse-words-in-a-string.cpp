class Solution {
public:
    string reverseWords(string s) {
        int i=0,j=0;
        string ans = "";
        while(i<s.size()){
            while(i<s.size() && s[i]== ' ')
            i++;
            if(i>= s.size())break;
            j = i+1;

            while(j<s.size() && s[j]!=' ')j++;
            string temp = s.substr(i,j-i);
            if(ans.size()==0)
            ans += temp;
            else
            ans = temp + " " + ans;
            i = j+1;
        }
        return ans;
    }
};