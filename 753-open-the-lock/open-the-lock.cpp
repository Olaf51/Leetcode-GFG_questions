class Solution {
public:
void solve(queue<string> &que, unordered_set<string>&dead, string &curr){

    for(int i=0;i<4;i++){
        char ch = curr[i];
        char inc = ch=='9'?'0':ch+1;
        char dec = ch=='0'?'9':ch-1;
        curr[i]  = dec;
            if(!dead.count(curr)) {
                dead.insert(curr);
                que.push(curr);
            }

            curr[i] = inc;
            if(!dead.count(curr)) {
                dead.insert(curr);
                que.push(curr);
            }
            curr[i] = ch;
    }
}
    int openLock(vector<string>& deadends, string target) {
        string start = "0000";
        unordered_set<string>st(begin(deadends),end(deadends));
        if(st.find(start)!=st.end())return -1;

        queue<string>que;
        que.push(start);
        int lvl = 0;
        while(!que.empty()){
            int n = que.size();
            while(n--){
                string curr = que.front();
                que.pop();
                if(curr == target)return lvl;
                solve(que,st,curr);
            }
            lvl++;
        }
        return -1;
        
    }
};