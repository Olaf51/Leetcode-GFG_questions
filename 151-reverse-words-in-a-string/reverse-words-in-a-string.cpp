class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int i=0;
        int j=0;
        int n = s.size();
        while(i<n && j<n){
            while(i<n && s[i] == ' ')i++;
            if(i>= n )break;
            j = i+1;
            while(j<n && s[j]!= ' ')j++;
            string temp = s.substr(i, j-i);
            if(ans.size() == 0)ans += temp;
            else
            ans = temp + " " + ans ;
            i = j+1;
        }
        return ans;
        
    }
};