class Solution {
public:
 int ope(int a, int b, string t){
     if(t=="+")return a+b;
     if(t=="-")return a-b;
      if(t=="*")return (long)a*(long)b;
       if(t=="/")return a/b;
       return -1;
 }
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(auto &t: tokens){
            if(t=="+" || t=="-" || t=="*" || t=="/"){
                int a = st.top();
                st.pop();
                  int b = st.top();
                st.pop();
                int res = ope(b,a,t);
                st.push(res);
            }
            else
            st.push(stoi(t));
        }
        return st.top();
        
    }
};