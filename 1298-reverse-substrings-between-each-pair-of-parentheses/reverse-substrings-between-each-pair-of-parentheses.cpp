class Solution {
public:
    string reverseParentheses(string s) {
        stack<int>st;
        string ans;
        int i=0;
        while(i<s.size()){
            if(s[i] == ')'){
                int l = st.top();
                st.pop();
                reverse(ans.begin() + l, ans.end());
            }
            else if(s[i] == '(')st.push(ans.size());
            else
            ans+= s[i];
            i++;
        }
        return ans;
    }
};