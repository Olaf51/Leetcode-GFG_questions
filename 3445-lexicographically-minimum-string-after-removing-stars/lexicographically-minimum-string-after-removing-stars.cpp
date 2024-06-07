class Solution {
public:
 struct comp{
    bool operator()(pair<char,int>&p1,pair<char,int>&p2){
        if(p1.first == p2.first)
        return p1.second < p2.second;
        return p1.first>p2.first;
    }
 };
    string clearStars(string s) {
        priority_queue<pair<char,int>,vector<pair<char,int>>,comp>pq;
        int n = s.size();
       
        for(int i=0;i<n;i++){
            if(s[i]== '*'){
              
                int id = pq.top().second;
                pq.pop();
                s[id] = '*';
            }
            else
            pq.push({s[i],i});
        }
       
       
        string ans="";
        for(int i=0;i<n;i++){
            if(s[i]=='*')continue;
            ans += s[i];
        }
        return ans;

    }
};