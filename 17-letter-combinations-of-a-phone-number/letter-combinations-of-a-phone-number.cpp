class Solution {
public:
string map[10] = {" "," ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
void solve(string digits, vector<string>&ans, string op, int index){
    if(index==digits.size()){
        ans.push_back(op);
        return ;
    }
    string temp = map[digits[index]-'0'];
    for(auto letter : temp){
        solve(digits,ans,op+letter,index+1);
    }
}
// void solve(string digits, vector<string>& ans, string op, string map[], int index){
//     if(index == digits.size()){
//         ans.push_back(op);
//         return ;
//     }
//     int num = digits[index] - '0';
//     string value = map[num];
//     for(int i=0;i<value.size();i++){
//         op.push_back(value[i]);
//         solve(digits,ans,op,map,index+1);
//         op.pop_back();
//     }
    

    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        if(digits.size() == 0)
          return ans;
        
        string op = "";
        
        int index = 0;
        solve(digits, ans, op, index);
        return ans;
        
    }
};