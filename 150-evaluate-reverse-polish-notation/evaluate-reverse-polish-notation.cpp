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
        unordered_map<string,function<int(int,int)>>mp = {
            {"+", [](int a, int b){return a+b;}},
            {"-", [](int a, int b){return a-b;}},
            {"*", [](int a, int b){return (long)a*(long)b;}},
            {"/", [](int a, int b){return a/b;}}
        };
        
        for(auto &t: tokens){
            if(t=="+" || t=="-" || t=="*" || t=="/"){
                int a = st.top();
                st.pop();
                  int b = st.top();
                st.pop();
                int res = mp[t](b,a);
                st.push(res);
            }
            else
            st.push(stoi(t));
        }
        return st.top();
        
    }
};